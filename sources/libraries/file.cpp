#include "file.hpp"

void file::input(std::ifstream &input, std::string &line, std::string prefix)
{
  getline(input, line);
}
