#pragma once
#include <iostream>

class Bus
{
    double Weight = 8000;
    double Speed = 40;
public:
    Bus()
    {
        std::cout << "Bus with weight:" << Weight << "kg and speed:" << Speed << "km/hour created" << std::endl;
    }
    ~Bus()
    {
        std::cout << "Bus with weight:" << Weight << "kg and speed:" << Speed << "km/hour destroyed" << std::endl;
    }

    void Tick()
    {
        std::cout << "Bus is waiting for people at the bus station" << std::endl;
    }
};