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

    void pow(lib::lines_type &lines);
    void sqrt(lib::lines_type &lines);
    void inc(lib::lines_type &lines);
    void sum(lib::lines_type &lines);
    void sub(lib::lines_type &lines);
    void mult(lib::lines_type &lines);
    void div(lib::lines_type &lines);

    lib::library_type &library_;
    std::map<key_type, function_type> commands_;
};
