#include <iostream>
#include "exceptions/FullQueueException.h"
#include "exceptions/PeekOnEmptyQueueException.h"
#include "exceptions/DequeueOnEmptyQueueException.h"

#ifndef QUEUE
#define QUEUE

template <typename dataType>
class Queue
{
protected:
    int size;
    const int capacity;

public:
    Queue(int _capacity = 100);
    Queue(const Queue &queue);
    virtual Queue<dataType> &enqueue(dataType value) = 0;
    virtual dataType dequeue() = 0;
    virtual dataType peek() const = 0;
    virtual void print() const = 0;
    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;
};

template <typename dataType>
Queue<dataType>::Queue(int _capacity) : capacity(_capacity)
{
}

template <typename dataType>
Queue<dataType>::Queue(const Queue &queue) : capacity(queue.capacity)
{
}

template <typename dataType>
bool Queue<dataType>::isEmpty() const
{
    return !this->size;
}

template <typename dataType>
bool Queue<dataType>::isFull() const
{
    return this->size == this->capacity;
}

template <typename dataType>
int Queue<dataType>::getSize() const
{
    return this->size;
}

#endif