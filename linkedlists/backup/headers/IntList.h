#include <iostream>
#include "Node.h"
#include <assert.h>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::string;
using std::to_string;

#ifndef INTLIST_INCLUDED
#define INTLIST_INCLUDED

template <class Type>
class IntList
{
private:
    Node<Type> *head;
    Node<Type> *tail;
    Node<Type> *cursor;
    int length;
    IntList<Type> *addToSides(int position, Type value);
    void removeHead();
    void removeNext(Node<Type> *node);

public:
    ~IntList();
    Node<Type> *getHead();
    Node<Type> *getTail();
    int getLength();
    void setHead(Node<Type> *node);
    void setTail(Node<Type> *node);
    void print();
    Node<Type> *get(int index);
    int findFirstIndex(Type value);
    Node<Type> *findFirstNode(Type value);
    IntList *append(Type value);
    IntList *push(Type value);
    bool Empty();
    IntList *insert(int index, Type value);
    IntList *remove(int index);
    IntList *removeOccurrences(Type value);
    IntList *concat(IntList list);
    string toString();
    friend ostream &operator<<(ostream &out, IntList<Type> &list);
};

#endif