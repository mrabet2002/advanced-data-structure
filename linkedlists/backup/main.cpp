#include<iostream>
#include"./headers/IntList.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
    IntList<int> list = IntList<int>(), list2 = IntList<int>();
    list.append(5);
    list2.append(2)->append(4)->append(-7)->append(5);
    list.push(5);
    cout << list << list2;
    list.remove(2)->remove(4);
    list.insert(2, 9);
    cout << list;
    list.concat(list2);
    cout << list;
    list.removeOccurrences(5);
    cout << list.get(3)->getValue();
    cout << list.findFirstIndex(1);
    cout << list.findFirstNode(4)->getValue();
    return 0;
}