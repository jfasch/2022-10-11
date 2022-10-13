#include <iostream>
using namespace std;


class Blah
{
public:
    Blah(int internal) : _i(internal) {}

    auto permit_access_to_internals()
    {
        return [&](int new_value_of_internal)
        {
            _i = new_value_of_internal;
        };
    }

    int internal() const { return _i; }

private:
    int _i;
};

int main()
{
    Blah b(42);

    auto setter = b.permit_access_to_internals();
    setter(666);

    cout << b.internal() << endl;

    return 0;
}
