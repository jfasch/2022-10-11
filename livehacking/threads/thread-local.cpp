#include <thread>
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono_literals;

thread_local int global_variable = 42;

int main()
{
    thread t1([]()
    {
        int counter = 0;
        while (true) {
            cout << "t1: " << global_variable << endl;
            this_thread::sleep_for(0.5s);
            if (counter++ == 7)
                global_variable = 666;
        }
    });

    thread t2([]()
    {
        while (true) {
            cout << "t2: " << global_variable << endl;
            this_thread::sleep_for(0.5s);
        }
    });

    t1.join();
    t2.join();
}
