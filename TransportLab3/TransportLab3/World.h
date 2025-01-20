#pragma once
#include <list>
#include <iostream>

#include "Transport.h"

class World
{
    std::list<Transport*> Transports;
public:
    World()
    {
        std::cout << "World created" << std::endl;
    }
    ~World()
    {
        for (auto transport : Transports)
        {
            delete transport;
        }
        Transports.clear();

        std::cout << "World destroyed" << std::endl;
    }

    const std::list<Transport*>& GetTransports() const
    {
        return Transports;
    }

    bool RemoveTransport(Transport* transport)
    {
        auto it = std::find(Transports.begin(), Transports.end(), transport);
        if (it != Transports.end())
        {
            delete* it;
            Transports.erase(it);
            return true;
        }
        return false;
    }

    void AddLightCar()
    {
        Transports.push_back(new LightCar());
    }
    void AddHeavyCar()
    {
        Transports.push_back(new HeavyCar());
    }
    void AddMotorcycle()
    {
        Transports.push_back(new Motorcycle());
    }
    void AddBus()
    {
        int positionCount = MyMath::Next(5) + 5;
        std::vector<Position> randomSchedule(positionCount);
        for (int i = 0; i < positionCount; i++)
        {
            randomSchedule[i] = Position(MyMath::Next(400), MyMath::Next(400));
        }

        Transports.push_back(new Bus(randomSchedule));
    }
    void Tick()
    {
        std::cout << "** World tick **" << std::endl;

        for (auto transport : Transports)
        {
            transport->Tick();
        }
    }

    void SaveToFile(std::string filename)
    {
        std::ofstream file(filename);
        for (auto transport : Transports)
        {
            transport->Save(file);
        }
        file.close();
    }
};