#include "sensors.h"
#include "smartptr.h"

#include <map>
#include <iostream>
#include <string>

using namespace std;


int main()
{
    map<string, SmartPtr> sensors;

    SmartPtr const_sensor(new ConstantSensor(36.5));
    SmartPtr random_sensor(new RandomSensor(35.3, 39.4));
    SmartPtr error_sensor(new ErrorSensor);

    sensors["const"] = const_sensor;
    sensors["random"] = random_sensor;
    sensors["error"] = error_sensor;

    for (auto& [name, sensor]: sensors)
        cout << name << ": " << sensor->get_temperature() << endl;

    return 0;
}
