#include <vector>
#include <iostream>

using namespace std;


struct point
{
    point(int x, int y) : _x(y), _y(y)
    {
        cout << "point::point()" << endl;
    }

    int _x, _y;
};

int main()
{
    {
        vector<int> v(6, 42);
        for (int value: v)
            cout << value << endl;
    }

    {
        vector<int> v{6, 42};
        for (int value: v)
            cout << value << endl;
    }

    cout << "()" << endl;
    point p1(1,2);
    cout << "{}" << endl;
    point p2{3,4};

    return 0;
}
