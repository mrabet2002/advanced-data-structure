#include <iostream>
#include "Node.h"
#include <assert.h>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::to_string;

#ifndef List_INCLUDED
#define List_INCLUDED

template <class Type>
class List
{
    Node<Type> *head;
    Node<Type> *tail;
    int length;
    List<Type> *addToSides(int position, Type value);
    void removeHead();
    void removeNext(Node<Type> *node);

protected:
    List();
    Node<Type> *getHead() const;
    Node<Type> *getTail() const;
    int getLength() const;
    void resetLength();
    void setHead(Node<Type> *node);
    void setTail(Node<Type> *node);
    void print();
    Node<Type> *get(int index) const;
    int findFirstIndex(Type value);
    Node<Type> *findFirstNode(Type value);
    List<Type> *addLast(Type value);
    List<Type> *addFirst(Type value);
    bool Empty() const;
    List<Type> *insert(int index, Type value);
    List<Type> *remove(int index);
    List<Type> *removeOccurrences(Type value);
    List<Type> *concat(List list);
    string toString();
    // template <typename T>
    // friend ostream &operator<<(ostream &out, const List<T> &list);
};
template <class Type>
List<Type>::List()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

template <class Type>
List<Type> *List<Type>::addToSides(int position, Type value)
{
    Node<Type> *node = new Node<Type>(value);
    if (this->tail != nullptr)
    {
        if (position == 0)
        {
            node->setNext(this->head);
            this->head = node;
        }
        else if (position == this->length)
        {
            this->tail->setNext(node);
            this->tail = node;
        }
    }
    else
        this->head = this->tail = node;
    this->length++;
    return this;
}

template <class Type>
Node<Type> *List<Type>::getHead() const
{
    return this->head;
}

template <class Type>
Node<Type> *List<Type>::getTail() const
{
    return this->tail;
}

template <class Type>
inline int List<Type>::getLength() const
{
    return this->length;
}

template <class Type>
void List<Type>::resetLength(){
    this->length = 0;
}

template <class Type>
void List<Type>::setHead(Node<Type> *node)
{
    this->head = node;
}

template <class Type>
void List<Type>::setTail(Node<Type> *node)
{
    this->tail = node;
}

template <class Type>
void List<Type>::print()
{
    if (!this->Empty())
    {
        cout << "[ ";
        Node<Type> *tmp = this->head;
        for (int i = 0; i < this->length; i++)
        {
            cout << tmp->getValue() << ", ";
            tmp = tmp->getNext();
        }
        cout << "\b\b ]\n";
        delete tmp;
    }
    else
    {
        cout << "[]" << endl;
    }
}

template <class Type>
inline Node<Type> *List<Type>::get(int index) const
{
    Node<Type> *tmp = this->head;
    for (int i = 0; i < this->length; i++)
    {
        if (i == index)
            return tmp;
        tmp = tmp->getNext();
    }
    return nullptr;
}

template <class Type>
List<Type> *List<Type>::addLast(Type value)
{
    return this->addToSides(this->length, value);
}

template <class Type>
List<Type> *List<Type>::addFirst(Type value)
{
    return this->addToSides(0, value);
}

template <class Type>
bool List<Type>::Empty() const
{
    return this->head == nullptr;
}

template <class Type>
List<Type> *List<Type>::insert(int index, Type value)
{
    if (index == 0)
        this->addFirst(value);
    else if (index == this->length)
        this->addLast(value);
    else if (index < this->length)
    {
        Node<Type> *newNode = new Node<Type>(value);
        Node<Type> *tmp = this->get(index - 1);

        newNode->setNext(tmp->getNext());
        tmp->setNext(newNode);

        this->length++;
    }
    return this;
}

template <class Type>
void List<Type>::removeHead()
{
    Node<Type> *tmp = this->head;
    if (this->length == 1)
        this->head = this->tail = nullptr;
    else
        this->head = this->head->getNext();

    tmp->setNext(nullptr);
    this->length--;
    delete tmp;
}

template <class Type>
List<Type> *List<Type>::remove(int index)
{
    if (index < this->length)
    {
        Node<Type> *tmp = this->head;
        if (index == 0)
            this->removeHead();
        else
            this->removeNext(this->get(index - 1));
    }
    return this;
}

template <class Type>
void List<Type>::removeNext(Node<Type> *node)
{
    assert(node != this->tail);
    Node<Type> *nodeToDelete = node->getNext();
    node->setNext(nodeToDelete->getNext());
    nodeToDelete->setNext(nullptr);

    if (this->tail == nodeToDelete)
        this->tail = node;
    this->length--;
    delete nodeToDelete;
}

template <class Type>
string List<Type>::toString()
{
    Node<Type> *tmp = this->head;
    string listAsString = "[ ";
    for (int i = 0; i < this->length; i++)
    {
        listAsString += to_string(tmp->getValue()) + ", ";
        tmp = tmp->getNext();
    }
    listAsString += "\b\b ]\n";
    return listAsString;
}

template <class Type>
List<Type> *List<Type>::removeOccurrences(Type value)
{
    Node<Type> *tmp = this->head;
    for (int i = 0; i < this->length; i++)
    {
        if (tmp->getNext()->getValue() == value)
        {
            this->removeNext(tmp);
            continue;
        }
        // cout << this->length << endl;
        tmp = tmp->getNext();
    }
    tmp = nullptr;
    if (this->head != nullptr & this->head->getValue() == value)
    {
        this->removeHead();
        this->length--;
    }
    return this;
}

template <class Type>
List<Type> *List<Type>::concat(List<Type> source)
{
    for (int i = 0; i < source.getLength(); i++)
    {
        this->addLast(source.head->getValue());
        source.head = source.head->getNext();
    }
    return this;
}

template <class Type>
int List<Type>::findFirstIndex(Type value)
{
    Node<Type> *tmp = this->head;
    for (int i = 0; i < this->length; i++)
    {
        if (tmp->getValue() == value)
            return i;
        tmp = tmp->getNext();
    }

    return -1;
}

template <class Type>
Node<Type> *List<Type>::findFirstNode(Type value)
{
    Node<Type> *tmp = this->head;
    for (int i = 0; i < this->length; i++)
    {
        if (tmp->getValue() == value)
            return tmp;
        tmp = tmp->getNext();
    }
    return nullptr;
}

// template <typename T>
// ostream &operator<<(ostream &out, const List<T> &list)
// {
//     if (list.head != nullptr)
//     {
//         out << "[ ";
//         Node<T> *tmp = list.getHead();
//         for (int i = 0; i < list.getLength(); i++)
//         {
//             out << tmp->getValue() << ", ";
//             tmp = tmp->getNext();
//         }
//         out << "\b\b ]\n";
//         delete tmp;
//     }
//     return out;
// }

#endif