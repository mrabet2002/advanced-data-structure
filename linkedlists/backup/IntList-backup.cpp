#include "./headers/IntList.h"

template <typename Type> 
IntList<Type>::~IntList()
{
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
}

template <typename Type>
IntList<Type> *IntList<Type>::addToSides(int position, Type value)
{
    Node<Type> *node = new Node(value);
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

Node *IntList::getHead()
{
    return this->head;
}

Node *IntList::getTail()
{
    return this->tail;
}

inline int IntList::getLength()
{
    return this->length;
}

void IntList::setHead(Node *node)
{
    this->head = node;
}

void IntList::setTail(Node *node)
{
    this->tail = node;
}

void IntList::print()
{
    cout << "[ ";
    Node *tmp = this->head;
    for (int i = 0; i < this->length; i++)
    {
        cout << tmp->getValue() << ", ";
        tmp = tmp->getNext();
    }
    cout << "\b\b ]\n";
    delete tmp;
}

inline Node *IntList::get(int index)
{
    Node *tmp = this->head;
    for (int i = 0; i < this->length; i++)
    {
        if (i == index)
            return tmp;
        tmp = tmp->getNext();
    }
    return NULL;
}

IntList *IntList::append(int value)
{
    return this->addToSides(this->length, value);
}

IntList *IntList::push(int value)
{
    return this->addToSides(0, value);
}

bool IntList::Empty(){
    return this->head == NULL;
}

IntList *IntList::insert(int index, int value)
{
    if (index == 0)
        this->push(value);
    else if (index == this->length)
        this->append(value);
    else if (index < this->length)
    {
        Node *newNode = new Node(value);
        Node *tmp = this->get(index - 1);

        newNode->setNext(tmp->getNext());
        tmp->setNext(newNode);

        this->length++;
    }
    return this;
}

void IntList::removeHead()
{
    Node *tmp = this->head;
    this->head = this->head->getNext();
    tmp->setNext(NULL);
    delete tmp;
}

IntList *IntList::remove(int index)
{
    if (index < this->length)
    {
        Node *tmp = this->head;
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

void IntList::removeNext(Node *node)
{
    assert(node != this->tail);
    Node *nodeToDelete = node->getNext();
    node->setNext(nodeToDelete->getNext());
    nodeToDelete->setNext(NULL);

    if (this->tail == nodeToDelete)
        this->tail = node;
    this->length--;
    delete nodeToDelete;
}

string IntList::toString()
{
    Node *tmp = this->head;
    string listAsString = "[ ";
    for (int i = 0; i < this->length; i++)
    {
        listAsString += to_string(tmp->getValue()) + ", ";
        tmp = tmp->getNext();
    }
    listAsString += "\b\b ]\n";
    return listAsString;
}

ostream &operator<<(ostream &out, IntList &list)
{
    if (list.head != NULL)
    {
        out << "[ ";
        Node *tmp = list.getHead();
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

IntList *IntList::removeOccurrences(int value)
{
    Node *tmp = this->head;
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

IntList *IntList::concat(IntList source)
{
    for (int i = 0; i < source.getLength(); i++)
    {
        this->append(source.head->getValue());
        source.head = source.head->getNext();
    }
    return this;
}

int IntList::findFirstIndex(int value)
{
    Node *tmp = this->head;
    for (int i = 0; i < this->length; i++)
    {
        if (tmp->getValue() == value)
            return i;
        tmp = tmp->getNext();
    }

    return -1;
}

Node *IntList::findFirstNode(int value)
{
    Node *tmp = this->head;
    for (int i = 0; i < this->length; i++)
    {
        if (tmp->getValue() == value)
            return tmp;
        tmp = tmp->getNext();
    }
    return NULL;
}