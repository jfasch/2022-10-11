#include <iostream>
using namespace std;

void lo_function(const std::string& s)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

void lo_function(std::string&& s)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

template <typename T>
void function(T&& t)
{
    cout << __PRETTY_FUNCTION__ << ": " << typeid(t).name() << endl;
    lo_function(std::forward<T>(t));
}

int main()
{
    std::string s("howdy");
    function(s);
    function(std::move(s));
    return 0;
}
