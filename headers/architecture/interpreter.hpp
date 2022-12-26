#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "library.hpp"
#include "preprocessor.hpp"
#include "processor.hpp"
#include "postprocessor.hpp"
#include "syntax.hpp"
#include "exception.hpp"
#include "terminal.hpp"
#include "file.hpp"
#include "database.hpp"

class Interpreter
{
  public:
    Interpreter (lib::line_type &path);
    Interpreter ();
    ~Interpreter();

  private:
    lib::library_type library_;

    void term_(); //работа с терминалом
    void file_();//работа с файлом

    Preprocessor preprocessor_;
    Processor processor_;
    Postprocessor postprocessor_;
};
