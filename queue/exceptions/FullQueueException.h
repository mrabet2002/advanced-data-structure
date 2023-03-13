#include <iostream>
#include "../../lib/exception.h"

#ifndef FULL_QUEUE_EXCEPTION
#define FULL_QUEUE_EXCEPTION

class FullQueueException : public Exception
{
public:
    FullQueueException();
};

FullQueueException::FullQueueException() {
    this->message = "\n\n--------------------------------\nFullQueueException: Queue is full\n--------------------------------\n";
}

#endif