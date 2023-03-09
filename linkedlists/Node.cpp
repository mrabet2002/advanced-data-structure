#include "./headers/Node.h"


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
Type Node<Type>::getValue()
{
    return this->value;
}

template <class Type>
Node<Type> *Node<Type>::getNext()
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