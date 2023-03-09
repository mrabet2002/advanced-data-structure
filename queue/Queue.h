#include <iostream>

#ifndef STACK_INCLUDED
#define STACK_INCLUDED

template <typename dataType>
class Queue
{
protected:
    int size;
    const int capacity;

public:
    Queue(int _capacity = 100);
    Queue(const Queue &queue);
    virtual Queue<dataType> *enqueue(dataType value) = 0;
    virtual dataType dequeue() = 0;
    virtual dataType peek() const = 0;
    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;
};

template <typename dataType>
Queue<dataType>::Queue(int _capacity)
{
    data = new dataType[this->capacity];
    this->size = 0;
}

template <typename dataType>
Queue<dataType>::Queue(const Queue &queue)
{
    data = new dataType[this->maxSize];
    for (int i = 0; i < this->size; i++)
        push(queue.data[i]);
}

template <typename dataType>
inline bool Queue<dataType>::isEmpty() const
{
    return !this->size;
}

template <typename dataType>
inline bool Queue<dataType>::isFull() const
{
    return this->size == this->capacity;
}

template <typename dataType>
inline int Queue<dataType>::getSize() const
{
    return this->size;
}

#endif