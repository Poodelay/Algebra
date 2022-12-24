#pragma once

#include "database.hpp"
#include "library.hpp"
#include <map>
#include <string>
#include <iostream>
#include <fstream>


class Preprocessor
{
public:

    Preprocessor(lib::library_type& library);

    using key_type = std::string;
    using function_type = void(Preprocessor::*)( lib::lines_type &);

    lib::library_type &library_;
    std::map <key_type, function_type> commands_;

    void set(lib::lines_type &lines); //создание переменной
    void del(lib::lines_type &lines); //удаление переменной
    void asg(lib::lines_type &lines); //изменение переменной
    void exs(lib::lines_type &lines); //существование переменной
};
