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
    Interpreter ();
    ~Interpreter();
  private:
    lib::library_type library_;
    //lib::line_type path_to_log;

    void term_(); //работа с терминалом
    //void file_(const lib::line_type &path_to_log);//работа с файлом

    Preprocessor preprocessor_;
    Processor processor_;
    Postprocessor postprocessor_;
    //std::fstream input_file_;

    //lib::line_type path;
    //void ReadFromFile(const lib::lines_type &lines); //считывание из файла
    //void ReadFromConsol(const lib::lines_type &lines); //считывание с консоли
};
