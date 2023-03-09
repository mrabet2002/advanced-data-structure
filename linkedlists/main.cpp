#include <iostream>
#include "./headers/Stack.h"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{

    // List<string> list, list2;
    // list.addLast("my");
    // list2.addLast("hello")->addLast("world")->addLast("name")->addLast("is");
    // list.addFirst("Hi");
    // cout << list.toString() << list2.toString();
    // list.print();
    // list2.print();
    // list.remove(2)->remove(5);
    // list.insert(2, "Ahmed");
    // cout << list;
    // list.print();
    // list.concat(list2);
    // list.print();
    // cout << list.toString();
    // list.removeOccurrences("world");
    // list.print();
    // cout << list.get(3)->getValue();
    // cout << list.findFirstIndex(1);
    // cout << list.findFirstNode(4)->getValue();

    try
    {
        Stack<int> s;
        s.push(5)->push(3)->push(4);
        s.print();
        Stack<int> s2(s);
        s2.print();
        cout << s.pop() << endl;
        s.print();
        cout << s.pop() << endl;
        s.print();
        cout << s.pop() << endl;
        s.print();
        cout << s.getSize() << s.peek();
    }
    catch (PeekOnEmptyStackException &peekOnEmptyStackException)
    {
        std::cerr << peekOnEmptyStackException.what() << '\n';
    }
    return 0;
}