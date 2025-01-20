#pragma once
#include <iostream>
#include "Position.h"

class LightCar
{
    double Weight = 2000;
    double Speed = 60;
    Position CurrentPosition;
public:
    LightCar()
    {
        std::cout << "Light car with weight:" << Weight << "kg and speed:" << Speed << "km/hour created" << std::endl;
        CurrentPosition = Position(0, 0);
    }

    ~LightCar()
    {
        std::cout << "Light car with weight:" << Weight << "kg and speed:" << Speed << "km/hour destroyed" << std::endl;
    }

    void Tick()
    {
        std::cout << "A light car is going somewhere, current location (" << CurrentPosition.x << "," << CurrentPosition.y << ")" << std::endl;
        CurrentPosition.x += 3;
        CurrentPosition.y += 5;
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