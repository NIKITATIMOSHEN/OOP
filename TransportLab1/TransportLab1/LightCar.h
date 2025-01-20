#pragma once
#include <iostream>

class LightCar 
{
    double Weight = 2000;
    double Speed = 60;
public:
    LightCar()
    {
        std::cout << "Light car with weight:" << Weight << "kg and speed:" << Speed << "km/hour created" << std::endl;
    }
    ~LightCar()
    {
        std::cout << "Light car with weight:" << Weight << "kg and speed:" << Speed << "km/hour destroyed" << std::endl;
    }

    void Tick()
    {
        std::cout << "A light car is going somewhere" << std::endl;
    }
};