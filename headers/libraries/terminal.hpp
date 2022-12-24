#pragma once

#include <fstream>
#include <iostream>
struct Pass
{
    template <typename... T>
    Pass(const T &...) {}
};

namespace term
{
    // prefix -- некоторое сообщение перед вводом, например, текст "enter here >> "
    void input(std::string &line, std::string prefix);
    template <typename... T>
    void display(const T &...t);
}

template <typename... T>
void term::display(const T &...t)
{
    Pass{(std::cout << t << ' ', 1)...};
    std::cout << '\n';
}
