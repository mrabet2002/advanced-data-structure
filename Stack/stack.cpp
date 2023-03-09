#include "stack.h"

template <typename dataType>
Stack<dataType>::Stack(int _maxSize) : maxSize(_maxSize)
{
    data = new dataType[maxSize];
    size = 0;
}

template <typename dataType>
Stack<dataType>::Stack(const Stack &stack) : maxSize(stack.maxSize)
{
    data = new dataType[maxSize];
    for (int i = 0; i < size; i++)
        push(stack.data[i]);
}

template <typename dataType>
bool Stack<dataType>::isEmpty() const
{
    return !size;
}

template <typename dataType>
bool Stack<dataType>::isFull() const
{
    return size == maxSize;
}

template <typename dataType>
Stack<dataType> *Stack<dataType>::push(dataType value)
{
    if (this->isFull())
        throw "PushException : Stack is full";
    data[size++] = value;
    return this;
}

template <typename dataType>
dataType Stack<dataType>::pop()
{
    if (this->isEmpty())
        throw "PopException : Stack is empty";
    return data[--size];
}

template <typename dataType>
dataType Stack<dataType>::peek() const
{
    if (this->isEmpty())
        throw "PopException : Stack is empty";
    return data[size - 1];
}

template <typename dataType>
int Stack<dataType>::getSize() const
{
    return size;
}

template <typename dataType>
Stack<dataType>::~Stack()
{
    delete[] data;
}
