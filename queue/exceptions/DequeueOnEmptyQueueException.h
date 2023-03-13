#include <iostream>
#include "../../lib/exception.h"

#ifndef DEQUEUE_ON_EMPTY_QUEUE_EXCEPTION
#define DEQUEUE_ON_EMPTY_QUEUE_EXCEPTION

class DequeueOnEmptyQueueException : public Exception
{
public:
    DequeueOnEmptyQueueException();
};

DequeueOnEmptyQueueException::DequeueOnEmptyQueueException() {
    this->message = "\n\n--------------------------------\nDequeueOnEmptyQueueException: Queue is Empty\n--------------------------------\n";
}

#endif