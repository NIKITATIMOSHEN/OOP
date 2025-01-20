#pragma once
#include <list>
#include "LightCar.h"
#include "Bus.h"
#include "Position.h"

class World
{
    // Використовуємо список, тому що кількість транспорту може динамічно змінюватись.
    // Окрім цього у нас немає потреби звертатись по індексу (наприклад для сортування)
    std::list<LightCar*> LightCars;
    std::list<Bus*> Buses;
public:
    World()
    {
        std::cout << "World created" << std::endl;
    }
    ~World()
    {
        for (auto car : LightCars)
        {
            delete car;
        }
        LightCars.clear();

        for (auto bus : Buses)
        {
            delete bus;
        }
        Buses.clear();

        std::cout << "World destroyed" << std::endl;
    }

    const std::list<LightCar*>& GetLightCars() const
    {
        return LightCars;
    }

    const std::list<Bus*>& GetBuses() const
    {
        return Buses;
    }

    bool RemoveLightCar(LightCar* car)
    {
        auto it = std::find(LightCars.begin(), LightCars.end(), car);
        if (it != LightCars.end())
        {
            delete* it;
            LightCars.erase(it);
            return true;
        }
        return false;
    }

    bool RemoveBus(Bus* bus)
    {
        auto it = std::find(Buses.begin(), Buses.end(), bus);
        if (it != Buses.end())
        {
            delete* it;
            Buses.erase(it);
            return true;
        }
        return false;
    }

    void AddLightCar()
    {
        LightCars.push_back(new LightCar());
    }
    void AddBus()
    {
        Buses.push_back(new Bus());
    }
    void Tick()
    {
        std::cout << "World tick start" << std::endl;

        for (auto car : LightCars)
        {
            car->Tick();
        }
        for (auto bus : Buses)
        {
            bus->Tick();
        }

        std::cout << "World tick end" << std::endl;
    }
};