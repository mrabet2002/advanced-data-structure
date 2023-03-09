#include <iostream>
#include "../../lib/exception.h"

#ifndef PEEK_ON_EMPTY_STACK_EXCEPTION
#define PEEK_ON_EMPTY_STACK_EXCEPTION

class PeekOnEmptyStackException : public Exception
{
public:
    PeekOnEmptyStackException();
};

PeekOnEmptyStackException::PeekOnEmptyStackException() {
    this->message = "\n\n--------------------------------\ntrying to peek on an empty stack\n--------------------------------\n";
}

#endif