#include <thread>
#include <iostream>
using namespace std;

int main()
{
    {
        thread t([](){for(;;);});
        cout << "id vor detach: " << t.native_handle() << endl;
        t.detach();
    }
    cout << "ich lebe noch" << endl;
    return 0;
}
