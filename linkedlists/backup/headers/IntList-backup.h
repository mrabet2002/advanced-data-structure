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
    IntList *addToSides(int position, Type value);
    void removeHead();
    void removeNext(Node<T> *node);

public:
    ~IntList();
    Node *getHead();
    Node *getTail();
    int getLength();
    void setHead(Node *node);
    void setTail(Node *node);
    void print();
    Node *get(int index);
    int findFirstIndex(int value);
    Node *findFirstNode(int value);
    IntList *append(int value);
    IntList *push(int value);
    bool Empty();
    IntList *insert(int index, int value);
    IntList *remove(int index);
    IntList *removeOccurrences(int value);
    IntList *concat(IntList list);
    string toString();
    friend ostream &operator<<(ostream &out, IntList &list);
};

#endif