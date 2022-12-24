#include "exception.hpp"

const char *exc::Exception::what() const noexcept
{
    return this->message_.c_str();
}

exc::Exception::Exception(const std::string &msg) noexcept : message_{msg}
{
}
