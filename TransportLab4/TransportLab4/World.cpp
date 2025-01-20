#include "World.h"

World::World(int transportCount)
{
    for (int i = 0; i < transportCount; i++)
    {
        switch (MyMath::Next(3))
        {
        case 0:
            Transports.push_back(new LightCar());
            break;
        case 1:
            Transports.push_back(new HeavyCar());
            break;
        case 2:
            Transports.push_back(new Motorcycle());
            break;
        }
    }

    auto allSchedules = Navigator::Instance().GetBusSchedules();
    for (int i = 0; i < allSchedules.size(); i++)
    {
        Transports.push_back(new Bus(allSchedules[i]));
    }
}

World::~World()
{
    for (auto transport : Transports)
    {
        delete transport;
    }
    Transports.clear();
}

std::list<const Transport*> World::GetTransports() const
{
    std::list<const Transport*> constTransports;
    for (Transport* transport : Transports)
    {
        constTransports.push_back(transport);
    }
    return constTransports;
}

void World::AddLightCar()
{
    Transports.push_back(new LightCar());
}

void World::AddHeavyCar()
{
    Transports.push_back(new HeavyCar());
}

void World::AddMotorcycle()
{
    Transports.push_back(new Motorcycle());
}

void World::AddBus()
{
    auto allSchedules = Navigator::Instance().GetBusSchedules();
    int randomIndex = MyMath::Next(allSchedules.size());
    Transports.push_back(new Bus(allSchedules[randomIndex]));
}

bool World::RemoveTransport(const Transport* car)
{
    for (auto it = Transports.begin(); it != Transports.end(); it++)
    {
        if (*it == car)
        {
            delete *it;
            Transports.erase(it);
            return true;
        }
    }
    return false;
}

void World::Tick()
{
    for (Transport* car : Transports)
        car->Tick();
}

void World::SaveToFile(std::string filename)
{
    std::ofstream file(filename);
    for (auto transport : Transports)
    {
        transport->Save(file);
    }
    file.close();
}
