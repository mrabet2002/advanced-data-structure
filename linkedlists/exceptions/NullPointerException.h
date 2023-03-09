#include <iostream>
#include "../../lib/exception.h"

#ifndef NULL_PTR_EXCEPTION
#define NULL_PTR_EXCEPTION

class NullPointerException : public Exception
{
public:
    NullPointerException();
};

NullPointerException::NullPointerException() {
    this->message = "\n\n--------------------------------\ntrying to call methode on a null pointer\n--------------------------------\n";
}

#endif