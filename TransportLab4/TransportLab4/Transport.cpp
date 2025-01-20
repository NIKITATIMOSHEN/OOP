#include "Transport.h"

Transport::Transport() {}

void Transport::SetCurrentPosition(const Position& position) {
    CurrentPosition = Navigator::Instance().FindClosestPositionOnRoad(position, Weight);
}

void Transport::SetDestination(const Position& position) {
    Destination = Navigator::Instance().FindClosestPositionOnRoad(position, Weight);
    PathToDestination = Navigator::Instance().CalculatePathToDestination(CurrentPosition, Destination, Weight);
}

Transport::Type Transport::GetCarType() const {
    return Type::None;
}

Position Transport::GetPosition() const {
    return CurrentPosition;
}

std::vector<Position> Transport::GetCurrentPath() const {
    return PathToDestination;
}

void Transport::Tick() {
    if (PathToDestination.size() < 2) {
        SetDestination(Position(MyMath::Next(400), MyMath::Next(400)));
        return;
    }

    double driveDistance = Speed * 0.1;
    double currentRoadDistance = MyMath::Distance(PathToDestination[0], PathToDestination[1]);
    double restDriveDistance = currentRoadDistance - driveDistance;

    if (restDriveDistance > 0) {
        Position moveVector = MyMath::CalcVectorNormalize(PathToDestination[0], PathToDestination[1]);
        Position newPosition(
            CurrentPosition.x + moveVector.x * driveDistance,
            CurrentPosition.y + moveVector.y * driveDistance
        );
        PathToDestination[0] = newPosition;
    }
    else {
        PathToDestination.erase(PathToDestination.begin());
    }

    CurrentPosition = PathToDestination[0];
}

// LightCar implementation
LightCar::LightCar() {
    Weight = 3000;
    Speed = 60;
    SetCurrentPosition(Position(MyMath::Next(400), MyMath::Next(400)));
    SetDestination(Position(MyMath::Next(400), MyMath::Next(400)));
}

Transport::Type LightCar::GetCarType() const {
    return Type::Light;
}

void LightCar::Save(std::ofstream& file)
{
    file << "Light car;" << " Current position (" << CurrentPosition.x << "," << CurrentPosition.y << ");"
        << " Destination position (" << Destination.x << "," << Destination.y << ");" << " Path to destination:";

    for (auto position : PathToDestination)
    {
        file << CurrentPosition.x << "," << CurrentPosition.y << ";";
    }
    file << std::endl;
}

// HeavyCar implementation
HeavyCar::HeavyCar() {
    Weight = 20000;
    Speed = 20;
    SetCurrentPosition(Position(MyMath::Next(400), MyMath::Next(400)));
    SetDestination(Position(MyMath::Next(400), MyMath::Next(400)));
}

Transport::Type HeavyCar::GetCarType() const {
    return Type::Heavy;
}

void HeavyCar::Tick() {
    if (TicksToRest > 0) {
        --TicksToRest;
        return;
    }

    if (MyMath::NextDouble() < 0.01) {
        TicksToRest = 20;
    }

    Transport::Tick();
}

void HeavyCar::Save(std::ofstream& file)
{
    file << "Heavy car;" << " Current position (" << CurrentPosition.x << "," << CurrentPosition.y << ");"
        << " Destination position (" << Destination.x << "," << Destination.y << ");"
        << " Ticks to wait: " << TicksToRest
        << " Path to destination:";

    for (auto position : PathToDestination)
    {
        file << CurrentPosition.x << "," << CurrentPosition.y << ";";
    }
    file << std::endl;
}

// Motorcycle implementation
Motorcycle::Motorcycle() {
    Weight = 400;
    Speed = 100;
    SetCurrentPosition(Position(MyMath::Next(400), MyMath::Next(400)));
    SetDestination(Position(MyMath::Next(400), MyMath::Next(400)));
}

Transport::Type Motorcycle::GetCarType() const {
    return Type::Motorcycle;
}

void Motorcycle::Tick() {
    if (TicksToGetGas > 1) {
        --TicksToGetGas;
        return;
    }
    if (MinTicksToNextGetGas > 0)
        MinTicksToNextGetGas--;

    if (TicksToGetGas == 1) {
        --TicksToGetGas;
        SetDestination(Position(MyMath::Next(400), MyMath::Next(400)));
        MinTicksToNextGetGas = 200;
    }

    if (MinTicksToNextGetGas == 0 && MyMath::NextDouble() < 0.005) {
        SetDestination(Navigator::Instance().GasStation);
    }

    if (MinTicksToNextGetGas == 0 && MyMath::Distance(CurrentPosition, Navigator::Instance().GasStation) < 0.0001) {
        TicksToGetGas = 40;
    }

    Transport::Tick();
}

void Motorcycle::Save(std::ofstream& file)
{
    file << "Motorcycle;" << " Current position (" << CurrentPosition.x << "," << CurrentPosition.y << ");"
        << " Destination position (" << Destination.x << "," << Destination.y << ");"
        << " Ticks to wait on gas station: " << TicksToGetGas
        << " Min ticks to next going to gas station: " << MinTicksToNextGetGas
        << " Path to destination:";

    for (auto position : PathToDestination)
    {
        file << CurrentPosition.x << "," << CurrentPosition.y << ";";
    }
    file << std::endl;
}

// Bus implementation
Bus::Bus(std::vector<Position> schedulePath) {
    Weight = 4000;
    Speed = 30;

    SchedulePath = schedulePath;
    SetCurrentPosition(SchedulePath[0]);

    PathToDestination = Navigator::Instance().CalculatePathToDestination(SchedulePath[CurrentStop], SchedulePath[CurrentStop], Weight);
}

Transport::Type Bus::GetCarType() const {
    return Type::Bus;
}

void Bus::Tick() {
    if (TicksToPeopleWait > 0) {
        TicksToPeopleWait--;
        return;
    }

    Transport::Tick();
    if (PathToDestination.size() == 1) {
        if (CurrentStop + 1 == SchedulePath.size()) {
            CurrentStop = 0;
            std::reverse(SchedulePath.begin(), SchedulePath.end());
        }
        TicksToPeopleWait = 40;
        PathToDestination = Navigator::Instance().CalculatePathToDestination(SchedulePath[CurrentStop], SchedulePath[CurrentStop + 1], Weight);
        CurrentStop++;
    }
}

void Bus::Save(std::ofstream& file)
{
    file << "Bus;" << " Current position (" << CurrentPosition.x << "," << CurrentPosition.y << ");"
        << " Destination position (" << Destination.x << "," << Destination.y << ");"
        << " Ticks to wait on stop: " << TicksToPeopleWait
        << " Path to destination:";

    for (auto position : PathToDestination)
    {
        file << CurrentPosition.x << "," << CurrentPosition.y << ";";
    }
    file << " Schedule: ";
    for (auto position : SchedulePath)
    {
        file << CurrentPosition.x << "," << CurrentPosition.y << ";";
    }
    file << std::endl;
}