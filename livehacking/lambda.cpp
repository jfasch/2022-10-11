#include <iostream>
#include <functional>
#include <string>
using namespace std;

function<void()> create_print_function(const string& msg)
{
    auto print_function = [msg]() -> void {
        cout << msg << endl;
    };
    return print_function;
}

void ach()
{
    cout << "ach" << endl;
}

int main()
{
    function<void()> hallo = create_print_function("hallo");
    hallo();

    hallo = create_print_function("joerg");
    hallo();

    hallo = ach;
    hallo();

    return 0;
}
