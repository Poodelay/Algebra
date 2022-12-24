#pragma once

#include <string>
#include <algorithm> // для перевода в капс
#include "library.hpp"
namespace stx
{
  std::list<std::string> split(std::string line, char separator);
  bool isBounded(std::string line, char bound);
  std::string toUppercase(std::string line);

  lib::integer_number_type STOI(const lib::line_type &line);
  lib::floating_point_type STOF(const lib::line_type &line);
  lib::line_type STOS(const lib::line_type &line);
}
