#pragma once

#include "algebra.hpp"
#include "terminal.hpp"
#include "library.hpp"
#include "exception.hpp"
#include "syntax.hpp"
#include "file.hpp"
#include <fstream>
#include <map>

class Processor
{
  public:
    Processor (lib::library_type& library);
    Processor (lib::library_type &library, lib::line_type &path);

    using key_type=std::string;
    using function_type = void (Processor::*)(lib::lines_type &);

    void pow(lib::lines_type &lines); //возведение в степень
    void sqrt(lib::lines_type &lines);//корень числа
    void inc(lib::lines_type &lines); //прибавление числа
    void sum(lib::lines_type &lines); //сумма переменных
    void sub(lib::lines_type &lines); //разность переменных
    void mult(lib::lines_type &lines);//произведение переменных
    void div(lib::lines_type &lines); //деление перменных

    lib::library_type &library_;
    std::map<key_type, function_type> commands_;
    bool flag_;
    lib::line_type path_;
};
