#include <iostream>
#include <chrono>
#include <future>

using namespace std::chrono_literals;

int main()
{
    auto answer = std::async(std::launch::async, [](){
        std::this_thread::sleep_for(3s);
        return 42;
    });
    std::cout << answer.get() << std::endl;
    return 0;
}
