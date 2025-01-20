#pragma once
#include <iostream>
#include "Position.h"

class Bus
{
    double Weight = 8000;
    double Speed = 40;
    Position CurrentPosition;
public:
    Bus()
    {
        std::cout << "Bus with weight:" << Weight << "kg and speed:" << Speed << "km/hour created" << std::endl;
        CurrentPosition = Position(0, 0);
    }
    ~Bus()
    {
        std::cout << "Bus with weight:" << Weight << "kg and speed:" << Speed << "km/hour destroyed" << std::endl;
    }

    void Tick()
    {
        std::cout << "Bus is waiting in location("<< CurrentPosition.x<< "," << CurrentPosition.y << ") for people at the bus station" << std::endl;
    }

    Position GetPosition()
    {
        return CurrentPosition;
    }
    double GetWeight()
    {
        return Weight;
    }
    double GetSpeed()
    {
        return Speed;
    }
};