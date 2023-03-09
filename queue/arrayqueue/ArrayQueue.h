#include <iostream>
#include "../Queue.h"
#ifndef ARRAY_STACK_INCLUDED
#define ARRAY_STACK_INCLUDED

template <typename dataType>
class ArrayQueue : public Stack<dataType>
{
private:
    dataType *data;
    int front;
    int end;
public:
    ArrayQueue(int _maxSize = 100);
    ArrayQueue(const ArrayQueue &arrayQueue);
    ~ArrayQueue();
    ArrayQueue<dataType> *enqueue(dataType value);
    dataType dequeue();
    dataType peek() const;
};

template <typename dataType>
ArrayQueue<dataType>::ArrayQueue(int _maxSize)
{
    data = new dataType[this->maxSize];
    this->size = 0;
}

template <typename dataType>
ArrayQueue<dataType>::ArrayQueue(const ArrayQueue &arrayQueue)
{
    data = new dataType[this->maxSize];
    for (int i = 0; i < this->size; i++)
        enqueue(arrayQueue.data[i]);
}

template <typename dataType>
ArrayQueue<dataType> *ArrayQueue<dataType>::enqueue(dataType value)
{
    if (this->isFull())
        throw "enqueueException : ArrayQueue is full";
    data[this->size++] = value;
    return this;
}

template <typename dataType>
dataType ArrayQueue<dataType>::dequeue()
{
    if (this->isEmpty())
        throw "dequeueException : ArrayQueue is empty";
    return data[--this->size];
}

template <typename dataType>
dataType ArrayQueue<dataType>::peek() const
{
    if (this->isEmpty())
        throw "dequeueException : ArrayQueue is empty";
    return data[this->size - 1];
}

template <typename dataType>
ArrayQueue<dataType>::~ArrayQueue()
{
    delete[] data;
}

#endif