#pragma once

#include <exception>
#include <string>

namespace exc
{
    class Exception : public std::exception
    {
    public:
        const char *what() const noexcept;

    protected:
        explicit Exception(const std::string &message) noexcept;

    private:
        const std::string message_;
    };

    struct invalid_data : public Exception
    {
        invalid_data(const std::string &message) : Exception{
                                                       "Invalid data. Code: " + message + "."} {}
    };

    struct unknown_data : public Exception
    {
        unknown_data(const std::string &message) : Exception{
                                                       "Unknown data. Code: " + message + "."} {}
    };

    struct unspecified_data : public Exception
    {
        unspecified_data(const std::string &message) : Exception{
                                                           "Unspecified data. Code: " + message + "."} {}
    };

    struct undefined_data : public Exception     {

        undefined_data(const std::string &message) : Exception{
                                                         "Undefined data. Code: " + message + "."} {}
    };
}
