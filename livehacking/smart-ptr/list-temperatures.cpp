#include "sensors.h"
#include <iostream>
#include <map>
#include <string>
#include <memory>

using namespace std;

int main()
{
    map<string, shared_ptr<Sensor>> sensors;

    auto const_sensor = make_shared<ConstantSensor>(36.5);
    auto random_sensor = make_shared<RandomSensor>(35.4, 39.4);

    sensors["const"] = std::move(const_sensor);
    sensors["random"] = random_sensor;

    if (const_sensor)
        cout << const_sensor->get_temperature() << endl;

    for (auto& [name, sensor]: sensors)
        cout << name << ": " << sensor->get_temperature() << endl;

    return 0;
}
