#include <iostream> 
using namespace std;

struct Inner
{
    int i, j;
};

struct Outer
{
    int o;
    Inner i;
};

int main()
{
    Outer outer = { 42, { 1, 2 }};
    auto [a, b] = outer;
    auto [i, j] = b;

    cout << a << ' ' << i << ' ' << j << endl;

    return 0;
}
