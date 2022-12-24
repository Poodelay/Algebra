#include "terminal.hpp"
#include <cstddef>
#include <iostream>

void term::input(std::string &line, std::string prefix /*,std::string_view changed_prefix*/)
{
  std::cout << prefix << ": ";
  getline(std::cin, line);
}
