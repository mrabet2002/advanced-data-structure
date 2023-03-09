#include <iostream>
#include "../../lib/exception.h"

#ifndef POP_ON_EMPTY_STACK_EXCEPTION
#define POP_ON_EMPTY_STACK_EXCEPTION

class PopOnEmptyStackException : public Exception
{
public:
    PopOnEmptyStackException();
};

PopOnEmptyStackException::PopOnEmptyStackException() {
    this->message = "\n\n--------------------------------\ntrying to pop on an empty stack\n--------------------------------\n";
}

#endif