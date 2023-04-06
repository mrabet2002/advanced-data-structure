#include <iostream>
#include "exception.h"

#ifndef OUT_OF_RANGE_EXCEPTION
#define OUT_OF_RANGE_EXCEPTION

class OutRangeException : public Exception
{
public:
    OutRangeException();
};

OutRangeException::OutRangeException() {
    this->message = "\n\n--------------------------------\nOutRangeException: pointer out of range!!\n--------------------------------\n";
}

#endif