#include <iostream>
#include "LightCar.h"
#include "Bus.h"
#include "Position.h"

int main()
{
    std::cout << "Start!\n";
    LightCar lightCar;
    Bus bus;

    for (int i = 0; i < 3; i++)
    {
        Position position(i, i * 5);
        std::cout << "Position with x " << position.x << " and y " << position.y << std::endl;
        lightCar.Tick();
        bus.Tick();
    }

    std::cout << "Stop!\n";
}
