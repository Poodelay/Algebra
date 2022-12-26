#pragma once

#include "library.hpp"
#include <fstream>

struct Passfile
{
  template <typename... T>
    Passfile(const T &...) {}
};

namespace file
{
  void input(std::ifstream &input, std::string &line, std::string prefix);
  template <typename... T>
    void write(lib::line_type &path, const T &...t);
}

  template <typename... T>
void file::write(lib::line_type &path, const T &...t)
{
  std::ofstream output (path, std::ios::app);
  Passfile{(output << t << ' ', 1)...};
  output << '\n';
  output.close();
}
