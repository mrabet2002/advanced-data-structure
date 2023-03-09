#include <iostream>
#include "List.h"
#include "../exceptions/PeekOnEmptyStackException.h"
#include "../exceptions/PopOnEmptyStackException.h"

#ifndef STACK_INCLUDED
#define STACK_INCLUDED

template <typename dataType>
class Stack : private List<dataType>
{
public:
    Stack();
    Stack(const Stack &stack);
    bool isEmpty() const;
    Stack<dataType> *push(dataType value);
    dataType pop();
    dataType peek() const;
    int getSize() const;
    void print();
};

template <typename dataType>
Stack<dataType>::Stack()
{
}

template <typename dataType>
Stack<dataType>::Stack(const Stack &stack)
{
    for (int i = stack.getSize()-1; i >=0; i--)
        push(stack.get(i)->getValue());
}

template <typename dataType>
bool Stack<dataType>::isEmpty() const
{
    return this->Empty();
}

template <typename dataType>
Stack<dataType> *Stack<dataType>::push(dataType value)
{
    this->addFirst(value);
    return this;
}

template <typename dataType>
dataType Stack<dataType>::pop()
{
    if(this->isEmpty()) throw PopOnEmptyStackException();
    dataType removedValue = this->peek();
    this->remove(0);
    return removedValue;
}

template <typename dataType>
dataType Stack<dataType>::peek() const
{
    if(this->isEmpty()) throw PeekOnEmptyStackException();
    return this->get(0)->getValue();
}

template <typename dataType>
int Stack<dataType>::getSize() const
{
    return this->getLength();
}

template <typename dataType>
inline void Stack<dataType>::print()
{
    List<dataType>::print();
}

#endif