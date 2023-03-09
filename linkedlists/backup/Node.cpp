#include "./headers/Node.h"


Node::Node(int value)
{
    this->value = value;
    this->next = NULL;
}

Node::~Node()
{
    this->value = 0;
    this->next = NULL;
}

int Node::getValue()
{
    return this->value;
}

Node *Node::getNext()
{
    return this->next;
}

void Node::setValue(int value)
{
    this->value = value;
}

void Node::setNext(Node *node)
{
    this->next = node;
}