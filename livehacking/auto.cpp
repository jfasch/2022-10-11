#include <iostream>
using namespace std;

int main()
{
    int i = 666;
    auto* pi = &i;
    auto pi1 = &i;
    cout << *pi << *pi1 << endl;
    return 0;
}
