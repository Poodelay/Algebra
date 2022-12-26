#include <iostream>

#include "interpreter.hpp"

int main(int argc, char *argv[])
{
  if (argc > 6) {
    lib::line_type path (argv[6]); // я так понял первые 5 вим сам заполняет
    Interpreter{path};
  } else {
    Interpreter{};
  }
  std::cout << "well done" << std::endl;
  return 0;
}
