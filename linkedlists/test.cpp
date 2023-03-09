#include <iostream>
#include <string>
#include <sstream>
#include <type_traits>

#define IS_OBJECT(...) std::cout << std::boolalpha << #__VA_ARGS__ \
                                 << (std::is_object_v<__VA_ARGS__> ? "\tis object\n" : "\tis not object\n")

using namespace std;

class Test
{
public:
    string name;
};
template <typename T>
string int_to_string(T i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

int main(int argc, char const *argv[])
{
    Test *t;
    string test = "test";
    string s = "test " + int_to_string(test);
    cout << is_class<Test>();
    return 0;
}
