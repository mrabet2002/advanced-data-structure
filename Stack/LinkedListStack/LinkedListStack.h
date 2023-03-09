#include <iostream>
#include "../../linkedlists/headers/List.h"
#include "../stack.h"
#include "../exceptions/PeekOnEmptyStackException.h"
#include "../exceptions/PopOnEmptyStackException.h"

#ifndef LinkedListStack_INCLUDED
#define LinkedListStack_INCLUDED

template <typename dataType>
class LinkedListStack : public List<dataType>, public Stack<dataType>
{
public:
    LinkedListStack();
    LinkedListStack(const LinkedListStack &lickedListStack);
    LinkedListStack<dataType> *push(dataType value);
    dataType pop();
    dataType peek() const;
    void print();
};

template <typename dataType>
LinkedListStack<dataType>::LinkedListStack()
{
}

template <typename dataType>
LinkedListStack<dataType>::LinkedListStack(const LinkedListStack &linkedListStack)
{
    for (int i = linkedListStack.getSize()-1; i >=0; i--)
        push(linkedListStack.get(i)->getValue());
}

template <typename dataType>
LinkedListStack<dataType> *LinkedListStack<dataType>::push(dataType value)
{
    this->addFirst(value);
    this->size++;
    return this;
}

template <typename dataType>
dataType LinkedListStack<dataType>::pop()
{
    if(this->isEmpty()) throw PopOnEmptyStackException();
    dataType removedValue = this->peek();
    this->remove(0);
    this->size--;
    return removedValue;
}

template <typename dataType>
dataType LinkedListStack<dataType>::peek() const
{
    if(this->isEmpty()) throw PeekOnEmptyStackException();
    return this->get(0)->getValue();
}

template <typename dataType>
inline void LinkedListStack<dataType>::print()
{
    List<dataType>::print();
}

#endif