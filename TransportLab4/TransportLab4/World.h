#pragma once
#include "Transport.h"

class World
{
private:
    std::list<Transport*> Transports;
public:
    World(int transportCount);
    ~World();
    std::list<const Transport*> GetTransports() const;

    void AddLightCar();
    void AddHeavyCar();
    void AddMotorcycle();
    void AddBus();
    bool RemoveTransport(const Transport* car);
    void Tick();
    void SaveToFile(std::string filename);
};