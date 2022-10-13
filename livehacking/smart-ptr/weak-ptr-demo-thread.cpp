#include "sensors.h"

#include <map>
#include <memory>
#include <thread>
#include <chrono>
#include <iostream>


int main()
{
    std::map<std::string, std::shared_ptr<Sensor>> sensors;
    sensors["rand1"] = std::make_shared<RandomSensor>(20, 40);
    sensors["rand2"] = std::make_shared<RandomSensor>(10, 30);
    sensors["const"] = std::make_shared<ConstantSensor>(36.5);

    bool running = true;

    std::thread measurement_thread([&running, sensor=sensors["rand1"]]() {
        while (running) {
            std::cout << sensor->get_temperature() << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
        }
    });

    std::this_thread::sleep_for(std::chrono::seconds(2));
    running = false;

    measurement_thread.join();

    return 0;
}
