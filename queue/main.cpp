#include <iostream>
#include "ArrayQueue/ArrayQueue.h"
#include "LinkedListQueue/LinkedListQueue.h"

using namespace std;

int main(int argc, char const *argv[])
{

    Queue<int> *a = new LinkedListQueue<int>();
    cout << a->isEmpty() << endl;
    cout << a->isFull() << endl;
    try
    {
        a->enqueue(5).enqueue(4).enqueue(3);
        a->print();
        cout << a->dequeue() << endl;
        cout << a->dequeue() << endl;
        cout << a->dequeue() << endl;
        a->enqueue(5).enqueue(4).enqueue(3);
        cout << a->dequeue() << endl;
        a->print();
        cout << a->peek();
    }
    catch (Exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}