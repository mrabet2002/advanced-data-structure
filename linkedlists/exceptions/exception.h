#include <iostream>

#ifndef EXCEPTION
#define EXCEPTION

class Exception : public std::exception
{
protected:
    std::string message;

public:
    Exception();
    Exception(std::string msg);
    std::string what();
};

Exception::Exception() {
    this->message = "\n\n--------------------------------\nGeneral Exception\n--------------------------------\n";
}

Exception::Exception(std::string msg) : message(msg) {}

std::string Exception::what()
{
    return message;
}

#endif