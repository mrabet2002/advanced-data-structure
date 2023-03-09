#include <iostream>
#ifndef STACK_INCLUDED
#define STACK_INCLUDED

template <typename dataType>
class Stack
{
protected:
    int size;
    const int maxSize;

public:
    Stack(int _maxSize = 100);
    Stack(const Stack &stack);
    bool isEmpty() const;
    bool isFull() const;
    virtual Stack<dataType> *push(dataType value) = 0;
    virtual dataType pop() = 0;
    virtual dataType peek() const = 0;
    int getSize() const;
    // ~Stack();
};

template <typename dataType>
Stack<dataType>::Stack(int _maxSize) : maxSize(_maxSize)
{
    size = 0;
}

template <typename dataType>
Stack<dataType>::Stack(const Stack &stack) : maxSize(stack.maxSize)
{
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
int Stack<dataType>::getSize() const
{
    return size;
}

#endif