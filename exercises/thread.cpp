#include <gtest/gtest.h>
#include <thread>
#include <future>



TEST(thread_suite, future_check)
{
    std::promise<int> promise;

    std::thread th([&promise]() {
        using namespace std::literals::chrono_literals;
        std::this_thread::sleep_for(0.5s);
        
        promise.set_value(42);
    });

    ASSERT_EQ(promise.get_future().get(), 42);

    th.join();
}


class BagCopy
{
    using Item = std::pair<std::string, int>;

    // ...
};
