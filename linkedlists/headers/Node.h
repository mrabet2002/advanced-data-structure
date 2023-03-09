#include <iostream>
#include "../exceptions/NullPointerException.h"
using std::cout;
using std::cin;
using std::endl;

#ifndef NODE_INCLUDED
#define NODE_INCLUDED

template <class Type>

class Node
{
private:
    Type value;
    Node<Type> *next;
public:
    Node(Type value);
    Node();
    Type getValue() const;
    Node<Type> *getNext() const;
    void setValue(Type value);
    void setNext(Node<Type> *node);
};


template <class Type>
Node<Type>::Node(Type value)
{
    this->value = value;
    this->next = NULL;
}

template <class Type>
Node<Type>::Node()
{
    this->value = 0;
    this->next = NULL;
}

template <class Type>
Type Node<Type>::getValue() const
{
    if (this == NULL) throw NullPointerException();
    return this->value;
}

template <class Type>
Node<Type> *Node<Type>::getNext() const
{
    return this->next;
}

template <class Type>
void Node<Type>::setValue(Type value)
{
    this->value = value;
}

template <class Type>
void Node<Type>::setNext(Node *node)
{
    this->next = node;
}

#endif