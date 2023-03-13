#include <iostream>
#include "../stack.h"
#ifndef ARRAY_STACK_INCLUDED
#define ARRAY_STACK_INCLUDED

template <typename dataType>
class ArrayStack : public Stack<dataType>
{
private:
    dataType *data;
public:
    ArrayStack(int _maxSize = 100);
    ArrayStack(const ArrayStack &arrayStack);
    ~ArrayStack();
    ArrayStack<dataType> *push(dataType value);
    dataType pop();
    dataType peek() const;
};

template <typename dataType>
ArrayStack<dataType>::ArrayStack(int _maxSize)
{
    data = new dataType[this->maxSize];
    this->size = 0;
}

template <typename dataType>
ArrayStack<dataType>::ArrayStack(const ArrayStack &ArrayStack)
{
    data = new dataType[this->maxSize];
    for (int i = 0; i < this->size; i++)
        push(ArrayStack.data[i]);
}

template <typename dataType>
ArrayStack<dataType> *ArrayStack<dataType>::push(dataType value)
{
    if (this->isFull())
        throw "PushException : ArrayStack is full";
    data[this->size++] = value;
    return this;
}

template <typename dataType>
dataType ArrayStack<dataType>::pop()
{
    if (this->isEmpty())
        throw PopOnEmptyStackException();
    return data[--this->size];
}

template <typename dataType>
dataType ArrayStack<dataType>::peek() const
{
    if (this->isEmpty())
        throw PeekOnEmptyStackException();
    return data[this->size - 1];
}

template <typename dataType>
ArrayStack<dataType>::~ArrayStack()
{
    delete[] data;
}

#endif