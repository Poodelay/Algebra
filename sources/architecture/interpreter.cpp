#include "interpreter.hpp"

Interpreter::Interpreter (lib::line_type &path) :
  library_ { {'i', 'f', '\"'}, &stx::STOI, &stx::STOF, &stx::STOS },
  preprocessor_{library_}, processor_{library_}, postprocessor_{library_}
{
  library_.set("path", path);
  Interpreter::file_();
}

Interpreter::Interpreter () :
  library_ { {'i', 'f', '\"'}, &stx::STOI, &stx::STOF, &stx::STOS },
  preprocessor_{library_}, processor_{library_}, postprocessor_{library_}
{
  Interpreter::term_();
}

Interpreter::~Interpreter() {}

void Interpreter::term_()
{
  lib::line_type COMMAND;
  lib::line_type STRING;
  lib::lines_type LINES;
  while(true)
  {
    term::input(STRING, "");
    LINES = stx::split(STRING, ',');
    COMMAND = stx::toUppercase(LINES.front());
    LINES.pop_front();
    if (COMMAND == "POW") {
      try {
        processor_.pow(LINES);
      } catch (...) {
        term::display("input data error");
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

void Interpreter::file_()
{
  lib::line_type path = library_.get<lib::line_type>("path");
  std::ifstream input (path);
  if (input.is_open()) {
    input.close();
    lib::line_type STRING;
    lib::line_type COMMAND;
    lib::lines_type LINES;
    std::streampos pos;
    while(true)
    {
      input.open(path);
      input.seekg(pos);
      file::input(input, STRING, "");
      LINES = stx::split(STRING, ',');
      COMMAND = stx::toUppercase(LINES.front());
      LINES.pop_front();
      input.close();
      if (COMMAND == "POW") {
        try {
          processor_.pow(LINES);
        } catch (...) {
          file::write(path, "input data error");
        }
      } else if (COMMAND == "INC") {
        try {
          processor_.inc(LINES);
        } catch (...) {
          file::write(path, "input data error");
        }
      } else if (COMMAND == "SUM") {
        try {
          processor_.sum(LINES);
        } catch (...) {
          file::write(path, "input data error");
        }
      } else if (COMMAND == "SUB") {
        try {
          processor_.sub(LINES);
        } catch (...) {
          file::write(path, "input data error");
        }
      } else if (COMMAND == "MULT") {
        try {
          processor_.mult(LINES);
        } catch (...) {
          file::write(path, "input data error");
        }
      } else if (COMMAND == "DIV") {
        try {
          processor_.div(LINES);
        } catch (...) {
          file::write(path, "input data error");
        }
      } else if (COMMAND == "SET") {
        try {
          preprocessor_.set(LINES);
        } catch (...) {
          file::write(path, "input data error");
        }
      } else if (COMMAND == "DEL") {
        try {
          preprocessor_.del(LINES);
        } catch (...) {
          file::write(path, "input data error");
        }
      } else if (COMMAND == "ASG") {
        try {
          preprocessor_.asg(LINES);
        } catch (...) {
          file::write(path, "input data error");
        }
      } else if (COMMAND == "SIZE") {
        try {
          postprocessor_.size(LINES);
        } catch (...) {
          file::write(path, "input data error");
        }
      } else if (COMMAND == "ANC") {
        try {
          postprocessor_.allNameConsol(LINES);
        } catch (...) {
          file::write(path, "input data error");
        }
      } else if (COMMAND == "CLC") {
        try {
          postprocessor_.clearPost(LINES);
        } catch (...) {
          file::write(path, "input data error");
        }
      } else if (COMMAND == "EXIT") {
        input.close();
        exit(0);
      } else if (COMMAND == "EXS") {
        try {
          postprocessor_.exs(LINES);
        } catch (...) {
          file::write(path, "input data error");
        }
      } else {
        file::write(path, "command entered incorrently");
      }
      input.open(path);
      input.seekg(std::ios::end);
      pos = input.tellg();
      input.close();
    }
  } else {
    input.close();
    term::display("file not found");
    this->term_();
  }
}
