#include <thread>
#include <iostream>
#include <chrono>
#include <future>

using namespace std::chrono_literals;

int main()
{
    std::promise<int> answer_promise;
    auto answer_future = answer_promise.get_future();

    std::thread chew_answer([&answer_promise]()
    {
        std::this_thread::sleep_for(3s);
        answer_promise.set_value(42);
    });

    std::cout << answer_future.get() << std::endl;

    chew_answer.join();

    return 0;
}
