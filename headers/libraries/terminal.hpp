#pragma once

#include "file.hpp"
#include "library.hpp"
#include <iostream>
#include <list>

struct Pass
{
  template <typename... T>
    Pass(const T &...) {}
};

namespace term
{
  void input(std::string &line, std::string prefix);
  template <typename... T>
    std::string display(const T &...t);
}

  template <typename... T>
std::string term::display(const T &...t)
{
  std::string line;
  std::list<std::string> lines;
  Pass {(std::cout << t << ' ', 1)...};
  std::cout << '\n';
  Pass{(lines.push_back(t), 1)...};
  for (auto it = lines.begin(); it != lines.end(); ++it) {
    for (std::size_t i = 0; i < (*it).size(); ++i) {
      line.push_back((*it)[i]);
    }
  }
  return line;
}
