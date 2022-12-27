#pragma once

#include <cstddef>
#include <stdexcept>
#include <tuple>
#include <memory>
#include <string>
#include <typeindex>
#include <map>
#include <list>

template <typename... Ts>
class Database
{
  public:

    template <typename T>
      using function_type = T (*)(const std::string &);
    using line_type = std::string;
    using lines_type = std::list<line_type>;
    using size_type = std::size_t;

    static constexpr size_type N {sizeof...(Ts)};
    struct Unit
    {
      std::shared_ptr<void> value{nullptr};
      std::type_index index{typeid(void)};
    };
    std::map<line_type, Unit> variables;

    Database(const char (&signs)[N], const function_type<Ts>... functions);
    ~Database();

    bool exists(line_type &name) const;
    void set(const line_type &name, const line_type &value);
    template <typename T>
      void set(const line_type &name, const T value);
    void erase(line_type &name);
    void assign(const line_type &value, const line_type &name);
    template<typename T>
      void assign(const T t, const line_type& name);
    size_type size() const;
    lines_type allNames() const;
    template<typename T>
      T get(const line_type &name);
    std::type_index getTypeId(const line_type &name);

    bool flag;

  private:
    line_type signs_;
    std::tuple<function_type<Ts>...> functions_;

    template <size_type I = 0, class Function, class Condition>
      void forEachConversionFunction_(const Function &function,
          const Condition &condition) const;

    bool find_(const char &a);
};

template <typename... Ts>
template <std::size_t I, class Func, class Cond>
void Database<Ts...>::forEachConversionFunction_(const Func &func,
    const Cond &cond) const
{
  if constexpr (I < N)
  {
    auto convFunc{std::get<I>(this->functions_)};
    if (cond(convFunc)) { func(convFunc); }
    else { this->forEachConversionFunction_<I + 1>(func, cond); }
  }
}

template <typename... Ts>
Database<Ts...>::Database(const char (&signs)[N], const function_type<Ts>... functions) :
  signs_{signs}, functions_{functions...}
{}

  template <typename... Ts>
Database<Ts...>::~Database()
{}

template <typename... Ts>
bool Database<Ts...>::exists(line_type &name) const
{
  auto it = this->variables.find(name);
  return it != this->variables.end()? 1 : 0;
}

template <typename... Ts>
void Database<Ts...>::set(const line_type& name, const line_type& value)
{
  if (!flag) {
    if (this->find_(value.back()))
    {
      this->flag = true;
      const auto& sign{value.back()};
      auto signs_ci{this->signs_.cbegin()};

      auto cond = [&](auto) {
        return ( sign == *(signs_ci++) );
      };

      auto func = [&](auto convFunc) {
        this->set(name, (*convFunc)(value));
      };

      this->forEachConversionFunction_(func, cond);
    }
  } else { this->set<line_type>(name, value); }
}

template <typename... Ts>
template <typename T>
void Database<Ts...>::set(const line_type &name, const T value)
{
  auto it = this->variables.find(name);
  if (it == this->variables.end()) {
    this->variables.insert({name, Unit{std::make_shared<T>(value),
        typeid(decltype(value))}});
  } else
    this->assign<T>(value, name);
}

template <typename... Ts>
void Database<Ts...>::assign(const line_type& value, const line_type& name)
{
  if (this->find_(value.back()))
  {
    const auto sign{value.back()};
    auto signs_ci{this->signs_.cbegin()};

    auto cond = [&](auto) {
      return ( sign == *(signs_ci++) );
    };

    auto func = [&](auto convFunc) {
      this->assign((*convFunc)(value), name);
    };

    this->forEachConversionFunction_(func, cond);
  }
}

template <typename... Ts>
template<typename T>
void Database<Ts...>::assign(const T value, const line_type &name)
{
  auto it = this->variables.find(name);
  if (it != this->variables.end())
    it->second = Unit{std::make_shared<T>(value), typeid(decltype(value))};
  else
    throw std::out_of_range("variable don't exist");
}

template <typename... Ts>
std::size_t Database<Ts...>::size() const
{
  return this->variables.size();
}

template <typename... Ts>
typename Database<Ts...>::lines_type Database<Ts...>::allNames() const
{
  lines_type names;
  size_type size = this->variables.size();
  auto it = this->variables.begin();
  for (size_type i = 0; i < size; ++i, ++it)
  {
    names.push_back(it->first);
  }
  return names;
}

template <typename... Ts>
void Database<Ts...>::erase(line_type &name)
{
  auto it = this->variables.find(name);
  if (it != this->variables.end())
    this->variables.erase(it);
  else
    throw std::out_of_range("variable don't exist");
}

template <typename... Ts>
template <typename T>
T Database<Ts...>::get(const line_type &name)
{
  auto it = this->variables.find(name);
  if (it != this->variables.end())
  {
    if (it->second.index == typeid(T))
      // std::shared_ptr: get(), operator*()
      return *(T*)it->second.value.get();
    else
      throw std::invalid_argument ("Variable type specified incorrectly");
  }
  else
    throw std::out_of_range ("variable don't exist");
}

template <typename... Ts>
bool Database<Ts...>::find_(const char& a)
{
  for (std::size_t i = 0; i < this->signs_.size(); ++i)
  {
    if (a == this->signs_[i]) {
      return true;
    }
  }
  throw std::invalid_argument("Variable type specified incorrectly");
}

template <typename... Ts>
std::type_index Database<Ts...>::getTypeId(const line_type &name)
{
  auto it = this->variables.find(name);
  if (it != this->variables.end())
    return it->second.index;
  else
    throw std::out_of_range("Variable don't exist");
}
