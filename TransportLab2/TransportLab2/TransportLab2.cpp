#include <iostream>
#include "World.h"

int main()
{
    std::cout << "Start!\n";
    World world;

    for (int i = 0; i < 3; i++)
    {
        world.AddLightCar();
        world.Tick();
    }
    world.AddBus();
    for (int i = 0; i < 3; i++)
    {
        world.Tick();
    }

    auto lightCars = world.GetLightCars();
    std::cout << "World has "<< lightCars.size() <<" light cars!" << std::endl;
    std::cout << "Remove one of cars !" << std::endl;

    world.RemoveLightCar(lightCars.front());
    lightCars = world.GetLightCars();
    std::cout << "World has " << lightCars.size() << " light cars!" << std::endl;

    std::cout << "Stop!\n";
}
