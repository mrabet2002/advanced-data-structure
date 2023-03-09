#include <iostream>

#ifndef POP_ON_EMPTY_STACK_EXCEPTION
#define POP_ON_EMPTY_STACK_EXCEPTION

class PopOnEmptyStackException : public std::exception
{
private:
    std::string message;

public:
    PopOnEmptyStackException();
    PopOnEmptyStackException(std::string msg);
    std::string what();
};

PopOnEmptyStackException::PopOnEmptyStackException() {
    this->message = "\n\n--------------------------------\ntrying to pop on an empty stack\n--------------------------------\n";
}

PopOnEmptyStackException::PopOnEmptyStackException(std::string msg) : message(msg) {}

std::string PopOnEmptyStackException::what()
{
    return message;
}

#endif