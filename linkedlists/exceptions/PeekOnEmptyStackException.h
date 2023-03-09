#include <iostream>

#ifndef PEEK_ON_EMPTY_STACK_EXCEPTION
#define PEEK_ON_EMPTY_STACK_EXCEPTION

class PeekOnEmptyStackException : public std::exception
{
private:
    std::string message;

public:
    PeekOnEmptyStackException();
    PeekOnEmptyStackException(std::string msg);
    std::string what();
};

PeekOnEmptyStackException::PeekOnEmptyStackException() {
    this->message = "\n\n--------------------------------\ntrying to peek on an empty stack\n--------------------------------\n";
}

PeekOnEmptyStackException::PeekOnEmptyStackException(std::string msg) : message(msg) {}

std::string PeekOnEmptyStackException::what()
{
    return message;
}

#endif