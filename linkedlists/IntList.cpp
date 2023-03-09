#include "./headers/IntList.h"


template <class Type>
IntList<Type> *IntList<Type>::addToSides(int position, Type value)
{
    Node<Type> *node = new Node<Type>(value);
    if (this->tail != NULL)
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
Node<Type> *IntList<Type>::getHead()
{
    return this->head;
}

template <class Type>
Node<Type> *IntList<Type>::getTail()
{
    return this->tail;
}

template <class Type>
inline int IntList<Type>::getLength()
{
    return this->length;
}

template <class Type>
void IntList<Type>::setHead(Node<Type> *node)
{
    this->head = node;
}

template <class Type>
void IntList<Type>::setTail(Node<Type> *node)
{
    this->tail = node;
}

template <class Type>
void IntList<Type>::print()
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

template <class Type>
inline Node<Type> *IntList<Type>::get(int index)
{
    Node<Type> *tmp = this->head;
    for (int i = 0; i < this->length; i++)
    {
        if (i == index)
            return tmp;
        tmp = tmp->getNext();
    }
    return NULL;
}

template <class Type>
IntList<Type> *IntList<Type>::append(Type value)
{
    return this->addToSides(this->length, value);
}

template <class Type>
IntList<Type> *IntList<Type>::push(Type value)
{
    return this->addToSides(0, value);
}

template <class Type>
bool IntList<Type>::Empty(){
    return this->head == NULL;
}

template <class Type>
IntList<Type> *IntList<Type>::insert(int index, Type value)
{
    if (index == 0)
        this->push(value);
    else if (index == this->length)
        this->append(value);
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
void IntList<Type>::removeHead()
{
    Node<Type> *tmp = this->head;
    this->head = this->head->getNext();
    tmp->setNext(NULL);
    delete tmp;
}

template <class Type>
IntList<Type> *IntList<Type>::remove(int index)
{
    if (index < this->length)
    {
        Node<Type> *tmp = this->head;
        if (this->length == 1)
        {
            this->head = this->tail = NULL;
            delete tmp;
        }
        else if (index == 0)
            this->removeHead();
        else
            this->removeNext(this->get(index - 1));
    }
    return this;
}

template <class Type>
void IntList<Type>::removeNext(Node<Type> *node)
{
    assert(node != this->tail);
    Node<Type> *nodeToDelete = node->getNext();
    node->setNext(nodeToDelete->getNext());
    nodeToDelete->setNext(NULL);

    if (this->tail == nodeToDelete)
        this->tail = node;
    this->length--;
    delete nodeToDelete;
}

template <class Type>
string IntList<Type>::toString()
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
ostream &operator<<(ostream &out, IntList<Type> &list)
{
    if (list.head != NULL)
    {
        out << "[ ";
        Node<Type> *tmp = list.getHead();
        for (int i = 0; i < list.getLength(); i++)
        {
            out << tmp->getValue() << ", ";
            tmp = tmp->getNext();
        }
        out << "\b\b ]\n";
        delete tmp;
    }
    return out;
}

template <class Type>
IntList<Type> *IntList<Type>::removeOccurrences(Type value)
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
    tmp = NULL;
    if (this->head != NULL & this->head->getValue() == value)
    {
        this->removeHead();
        this->length--;
    }
    return this;
}

template <class Type>
IntList<Type> *IntList<Type>::concat(IntList<Type> source)
{
    for (int i = 0; i < source.getLength(); i++)
    {
        this->append(source.head->getValue());
        source.head = source.head->getNext();
    }
    return this;
}

template <class Type>
int IntList<Type>::findFirstIndex(Type value)
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
Node<Type> *IntList<Type>::findFirstNode(Type value)
{
    Node<Type> *tmp = this->head;
    for (int i = 0; i < this->length; i++)
    {
        if (tmp->getValue() == value)
            return tmp;
        tmp = tmp->getNext();
    }
    return NULL;
}