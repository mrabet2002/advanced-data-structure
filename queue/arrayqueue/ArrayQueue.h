#include <iostream>
#include "../Queue.h"
#ifndef ARRAY_STACK_INCLUDED
#define ARRAY_STACK_INCLUDED

template <typename dataType>
class ArrayQueue : public Queue<dataType>
{
private:
    dataType *data;
    int front;
    int end;

public:
    ArrayQueue(int _capacity = 100);
    ArrayQueue(const ArrayQueue &arrayQueue);
    ~ArrayQueue();
    ArrayQueue<dataType> &enqueue(dataType value);
    dataType dequeue();
    dataType peek() const;
    void print() const;
    bool isEmpty() const;
    bool isFull() const;
};

template <typename dataType>
ArrayQueue<dataType>::ArrayQueue(int _capacity)
    : Queue<dataType>(_capacity)
{
    data = new dataType[this->capacity];
    front = end = 0;
}

template <typename dataType>
ArrayQueue<dataType>::ArrayQueue(const ArrayQueue &arrayQueue)
{
    data = new dataType[arrayQueue.capacity];
    front = arrayQueue.front;
    end = arrayQueue.end;
    int i = front;
    while (i < end)
        enqueue(arrayQueue.data[i]);
}

template <typename dataType>
ArrayQueue<dataType> &ArrayQueue<dataType>::enqueue(dataType value)
{
    if (this->isFull())
        throw FullQueueException();
    data[(end++) % this->capacity] = value;
    return *this;
}

template <typename dataType>
dataType ArrayQueue<dataType>::dequeue()
{
    if (this->isEmpty())
        throw DequeueOnEmptyQueueException();
    return data[(front++) % this->capacity];
}

template <typename dataType>
dataType ArrayQueue<dataType>::peek() const
{
    if (this->isEmpty())
        throw PeekOnEmptyQueueException();
    return data[front];
}

template <typename dataType>
void ArrayQueue<dataType>::print() const
{
    int i = front;
    while (i < end)
        std::cout << data[(i++)%this->capacity] << "\t";
    std::cout << "\n";
}

template <typename dataType>
bool ArrayQueue<dataType>::isEmpty() const
{
    return front == end;
}

template <typename dataType>
bool ArrayQueue<dataType>::isFull() const
{
    return (end + 1) % this->capacity == front;
}

template <typename dataType>
ArrayQueue<dataType>::~ArrayQueue()
{
    delete[] data;
}

#endif