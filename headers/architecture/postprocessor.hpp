#pragma once

#include "terminal.hpp"
#include "database.hpp"
#include "library.hpp"
#include <map>
#include <string>
#include <list>
#include <ios>

class Postprocessor
{
public:
    Postprocessor(lib::library_type& library);

    using key_type=std::string;
    using function_type = void(Postprocessor::*)( lib::lines_type &);

    lib::library_type &library_;
    std::map<key_type, function_type> commands_;

    void size ( lib::lines_type &lines);
    void allNameConsol ( lib::lines_type &lines);
    void clearPost( lib::lines_type &lines);
    void exs(lib::lines_type &lines);
};
