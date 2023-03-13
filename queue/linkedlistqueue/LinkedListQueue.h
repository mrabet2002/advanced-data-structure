#include <iostream>
#include "../../linkedlists/headers/List.h"
#include "../Queue.h"

#ifndef LINKED_LIST_QUEUE
#define LINKED_LIST_QUEUE

template <typename dataType>
class LinkedListQueue : public List<dataType>, public Queue<dataType>
{
public:
    LinkedListQueue();
    LinkedListQueue(const LinkedListQueue &lickedListStack);
    LinkedListQueue<dataType> &enqueue(dataType value);
    dataType dequeue();
    dataType peek() const;
    void print() const;
};

template <typename dataType>
LinkedListQueue<dataType>::LinkedListQueue()
{
}

template <typename dataType>
LinkedListQueue<dataType>::LinkedListQueue(const LinkedListQueue &linkedListQueue)
{
    for (int i = linkedListQueue.getSize()-1; i >=0; i--)
        push(linkedListQueue.get(i)->getValue());
}

template <typename dataType>
LinkedListQueue<dataType> &LinkedListQueue<dataType>::enqueue(dataType value)
{
    this->addLast(value);
    this->size++;
    return *this;
}

template <typename dataType>
dataType LinkedListQueue<dataType>::dequeue()
{
    if(this->isEmpty()) throw DequeueOnEmptyQueueException();
    dataType removedValue = this->peek();
    this->remove(0);
    this->size--;
    return removedValue;
}

template <typename dataType>
dataType LinkedListQueue<dataType>::peek() const
{
    if(this->isEmpty()) throw PeekOnEmptyQueueException();
    return this->get(0)->getValue();
}

template <typename dataType>
inline void LinkedListQueue<dataType>::print() const
{
    List<dataType>::print();
}

#endif