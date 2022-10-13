#include <iostream>
using namespace std;

int b = 42;
const int& rb = b*2;

int main()
{
    int a = 42;
    const int& r = a*2;

    cout << r << endl;

    a = 666;
    cout << r << endl;

    cout << &r << endl;
    cout << &rb << endl;

    int* harhar = (int*)&r;
    *harhar = 666;

    return 0;
}
