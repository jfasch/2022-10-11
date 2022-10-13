#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int main()
{
    mutex m;
    int i = 0;

    auto incrementer = [&i, &m](){
        int num = 10000000;
        m.lock();
        while (num--) {
            i++;
        }
        m.unlock();
    };

    thread t1(incrementer);
    thread t2(incrementer);

    t1.join();
    t2.join();

    cout << i << endl;
    return 0;
}
