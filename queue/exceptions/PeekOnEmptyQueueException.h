#include <iostream>
#include "../../lib/exception.h"

#ifndef PEEK_ON_EMPTY_QUEUE_EXCEPTION
#define PEEK_ON_EMPTY_QUEUE_EXCEPTION

class PeekOnEmptyQueueException : public Exception
{
public:
    PeekOnEmptyQueueException();
};

PeekOnEmptyQueueException::PeekOnEmptyQueueException() {
    this->message = "\n\n--------------------------------\nPeekOnEmptyQueueException: Queue is Empty\n--------------------------------\n";
}

#endif