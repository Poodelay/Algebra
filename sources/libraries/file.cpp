#include "file.hpp"

void file::read(std::fstream &input, std::string &line) //, std::string_view path)
{
    input >> line;
}

void file::write(std::fstream &output, const std::string &line) //, std::string_view path)
{
    output << line;
}
