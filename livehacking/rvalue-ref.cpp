#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a = 42;
    // int&& r = a;    <--- error: cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
    int&& r = a*2;
 
    cout << r << endl;
    cout << &r << endl;

    r = 666;

    std::vector<int> v;
    v.push_back(r);    // <--- const &  (lvalue)
    v.push_back(a*2);
    v.push_back(std::move(12));
    v.push_back(std::move(a));

    cout << a << endl;

    return 0;
}
