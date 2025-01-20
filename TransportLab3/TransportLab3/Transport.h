#pragma once
#include "MyMath.h"
#include <vector>
#include <iostream>
#include <fstream>

class Transport {
public:
    enum class Type {
        Light,
        Heavy,
        Motorcycle,
        Bus,
        None
    };
protected:
    double Weight = 0;
    double Speed = 0;
    Position CurrentPosition{ 0, 0 };
    Position Destination{ 0, 0 };
    std::vector<Position> PathToDestination;

public:
    Transport();
    virtual ~Transport() = default;

    void SetCurrentPosition(const Position& position);
    void SetDestination(const Position& position);
    virtual Type GetCarType() const;
    Position GetPosition() const;
    std::vector<Position> GetCurrentPath() const;
    virtual void Tick();
    virtual void Save(std::ofstream& file) {};
};

class LightCar : public Transport {
public:
    LightCar();
    Type GetCarType() const override;
    void Save(std::ofstream& file) override;
};

class HeavyCar : public Transport {
private:
    int TicksToRest = 0;

public:
    HeavyCar();
    Type GetCarType() const override;
    void Save(std::ofstream& file) override;
    void Tick() override;
};

class Motorcycle : public Transport {
private:
    int TicksToGetGas = 0;
    int MinTicksToNextGetGas = 0;

public:
    Motorcycle();
    Type GetCarType() const override;
    void Save(std::ofstream& file) override;
    void Tick() override;
};

class Bus : public Transport {
private:
    int TicksToPeopleWait = 0;
    std::vector<Position> SchedulePath;
    int CurrentStop = 0;

public:
    Bus(std::vector<Position> schedulePath);
    Type GetCarType() const override;
    void Save(std::ofstream& file) override;
    void Tick() override;
};