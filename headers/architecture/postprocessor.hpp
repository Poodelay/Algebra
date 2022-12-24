#pragma once

#include "terminal.hpp"
#include "database.hpp"
#include "library.hpp"
#include <map>
#include <string>
#include <list>

class Postprocessor
{
public:
    Postprocessor(lib::library_type& library);

    using key_type=std::string;
    using function_type = void(Postprocessor::*)( lib::lines_type &);

    lib::library_type &library_;
    std::map<key_type, function_type> commands_;

    void size ( lib::lines_type &lines); //размер листа (кол-во переменных)
    void allNameConsol ( lib::lines_type &lines);//вывод в консоль все имена переменных
//    void allNameFile ( lib::lines_type &lines); //вывод в файл все имена переменных
    void clearPost( lib::lines_type &lines); //отчистка файла/консоли
    void exs(lib::lines_type &lines);
};
