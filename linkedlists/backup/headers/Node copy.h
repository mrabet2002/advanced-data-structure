#include <iostream>

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
    ~Node();
    Type getValue();
    Node<Type> *getNext();
    void setValue(Type value);
    void setNext(Node<Type> *node);
};

#endif