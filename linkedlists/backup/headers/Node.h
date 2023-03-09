#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#ifndef NODE_INCLUDED
#define NODE_INCLUDED

typedef <typename T>
class Node
{
private:
    int value;
    Node *next;
public:
    Node(int value);
    ~Node();
    int getValue();
    Node *getNext();
    void setValue(int value);
    void setNext(Node *node);
};

#endif