#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>
#include <chrono>
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace std::chrono_literals;

class MTQueue
{
public:
    MTQueue(size_t maxsize) : _maxsize(maxsize) {}

    void stop()
    {
        _stop = true;
        _notfull.notify_all();
        _notempty.notify_all();
    }
    bool stop_requested() const { return _stop; }

    void push(int i)
    {
        unique_lock<mutex> guard(_lock);
        {
            _notfull.wait(guard, [this](){ return _queue.size() != _maxsize || _stop; });
            if (_stop)
                throw runtime_error("stopped");
            _queue.push_back(i);
        }

        _notempty.notify_one();
    }

    int pop()
    {
        int rv;
        {
            unique_lock<mutex> guard(_lock);

            _notempty.wait(guard, [this](){ return _queue.size()>0 || _stop; });
            if (_stop)
                throw runtime_error("stopped");

            rv = _queue.front();
            _queue.pop_front();
        }
        _notfull.notify_one();
        
        return rv;
    }

private:
    deque<int> _queue;
    size_t _maxsize;
    mutex _lock;
    condition_variable _notempty;
    condition_variable _notfull;
    bool _stop = false;
};

int main()
{
    MTQueue queue(4);

    auto prod_func = [&queue]()
    {
        try {
            for (int i=0;; i++) {
                queue.push(i);
                this_thread::sleep_for(0.2s);
            }
        }
        catch (const runtime_error&)
        {
            cerr << "producer stopped" << endl;
        }
    };

    auto cons_func = [&queue]()
    {
        try {
            for (;;) {
                int i = queue.pop();
                cout << i << endl;
                this_thread::sleep_for(0.1s);
            }
        }
        catch (const runtime_error&) {
            cerr << "consumer stopped" << endl;
        }
    };

    thread producer1(prod_func);
    thread producer2(prod_func);
    thread producer3(prod_func);

    thread consumer1(cons_func);
    thread consumer2(cons_func);
    thread consumer3(cons_func);

    this_thread::sleep_for(10s);
    queue.stop();

    producer1.join();
    producer2.join();
    producer3.join();
    consumer1.join();
    consumer2.join();
    consumer3.join();

    return 0;
}
