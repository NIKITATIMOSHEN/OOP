#include <iostream>
#include "World.h"

int main()
{
    std::cout << "Start!\n";
    World world;

    for (int i = 0; i < 3; i++)
    {
        world.AddLightCar();
        world.AddBus();
        world.AddHeavyCar();
        world.AddMotorcycle();
        world.Tick();
    }

    for (int i = 0; i < 400; i++)
    {
        world.Tick();
    }

    world.SaveToFile("world.txt");

    std::cout << "Stop!\n";
}
