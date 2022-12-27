#include "interpreter.hpp"
#include "file.hpp"
#include "library.hpp"
#include "syntax.hpp"
#include "terminal.hpp"
#include <fstream>

Interpreter::Interpreter (lib::line_type &path) :
  library_ { {'i', 'f', '\"'}, &stx::STOI, &stx::STOF, &stx::STOS },
  preprocessor_{library_}, processor_{library_}, postprocessor_{library_}
{
  library_.set<lib::line_type>("path", path);
  Interpreter::program_();
}

Interpreter::~Interpreter() {}

void Interpreter::program_()
{
  lib::line_type path = this->library_.get<lib::line_type>("path");
  std::ofstream output (path);
  output.close();
  std::ifstream input(path);
  if (input.is_open()) {
    input.close();
    lib::line_type STRING, COMMAND;
    lib::lines_type LINES;
    while (true) {
      term::input(STRING, "");
      file::write(path, STRING);
      LINES = stx::split(STRING, ',');
      COMMAND = stx::toUppercase(LINES.front());
      LINES.pop_front();
      if (COMMAND == "POW") {
        try {
          processor_.pow(LINES);
        } catch (...) {
          term::display("input data error", path);
        }
      } else if (COMMAND == "SQRT") {
        try {
          processor_.sqrt(LINES);
        } catch (...) {
          term::display("input data error");
        }
      } else if (COMMAND == "INC") {
        try {
          processor_.inc(LINES);
        } catch (...) {
          term::display("input data error");
        }
      } else if (COMMAND == "SUM") {
        try {
          processor_.sum(LINES);
        } catch (...) {
          term::display("input data error");
        }
      } else if (COMMAND == "SUB") {
        try {
          processor_.sub(LINES);
        } catch (...) {
          term::display("input data error");
        }
      } else if (COMMAND == "MULT") {
        try {
          processor_.mult(LINES);
        } catch (...) {
          term::display("input data error");
        }
      } else if (COMMAND == "DIV") {
        try {
          processor_.div(LINES);
        } catch (...) {
          term::display("input data error");
        }
      } else if (COMMAND == "SET") {
        try {
          preprocessor_.set(LINES);
        } catch (...) {
          term::display("input data error");
        }
      } else if (COMMAND == "DEL") {
        try {
          preprocessor_.del(LINES);
        } catch (...) {
          term::display("input data error");
        }
      } else if (COMMAND == "ASG") {
        try {
          preprocessor_.asg(LINES);
        } catch (...) {
          term::display("input data error");
        }
      } else if (COMMAND == "SIZE") {
        try {
          postprocessor_.size(LINES);
        } catch (...) {
          term::display("input data error");
        }
      } else if (COMMAND == "ANC") {
        try {
          postprocessor_.allNameConsol(LINES);
        } catch (...) {
          term::display("input data error");
        }
      } else if (COMMAND == "CLC") {
        try {
          postprocessor_.clearPost(LINES);
        } catch (...) {
          term::display("input data error");
        }
      } else if (COMMAND == "EXIT") {
        exit(0);
      } else if (COMMAND == "EXS") {
        try {
          postprocessor_.exs(LINES);
        } catch (...) {
          term::display("input data error");
        }
      } else {
        term::display("command entered incorrently");
      }
    }
  }
}
