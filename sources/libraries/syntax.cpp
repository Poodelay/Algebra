#include "syntax.hpp"

std::list<std::string> stx::split(std::string line, char sep)
{
  lib::lines_type result;
  lib::line_type string;
  lib::size_type i = 0;
  while (i < line.size()) {
    while (line[i] != sep && line[i] != ' ' && line[i] != '\0') {
      string.push_back(line[i]);
      ++i;
    }
    if (line[i] == '\0') {
      result.push_back(string);
      return result;
    }
    while (line[i] == sep || line[i] == ' ') { ++i; }
    result.push_back(string);
    string.clear();
  }
  return result;
}

std::string stx::toUppercase(std::string line)
{
  std::transform(line.begin(), line.end(), line.begin(), ::toupper);
  return line;
}

bool stx::isBounded(std::string line, char bound)
{
  if (line.front() == bound && line.back() == bound)
  {
    return true;
  }
  return false;
}

lib::integer_number_type stx::STOI(const lib::line_type &line)
{
  lib::line_type line_ (line.begin(), --line.end());
  lib::integer_number_type value;
  value = std::stoi(line_);
  return value;
}

lib::floating_point_type stx::STOF(const lib::line_type &line)
{
  lib::line_type line_ (line.begin(), --line.end());
  lib::floating_point_type value;
  value = std::stof(line_);
  return value;
}

lib::line_type stx::STOS(const lib::line_type &line)
{
  lib::line_type path (++line.begin(), --line.end());
  return path;
}
