#include <iostream>
#include <string>
#include "World.h"

std::string PositionAsString(Position position)
{
    return "(" + std::to_string(position.x) + "," + std::to_string(position.y) + ")";
}

void PrintWorldInfo(const World& world)
{
    auto transports = world.GetTransports();
    std::cout << "Count of transports " << transports.size() << std::endl;
    for (auto transport : transports)
    {
        std::cout << "Type: ";
        switch (transport->GetCarType())
        {
        case Transport::Type::Light:
            std::cout << "Light car";
            break;
        case Transport::Type::Heavy:
            std::cout << "Heavy car";
            break;
        case Transport::Type::Motorcycle:
            std::cout << "Motorcycle";
            break;
        case Transport::Type::Bus:
            std::cout << "Bus";
            break;
        default:
            break;
        }

        std::cout << "; Current position: " << PositionAsString(transport->GetPosition()) << std::endl;
    }
}

int main()
{
    std::cout << "Create world with 5 cars and some buses!\n";
    World world(5);
    PrintWorldInfo(world);

    std::cout << "Do 10 Ticks" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        world.Tick();
    }
    PrintWorldInfo(world);

    std::cout << "Add some transports" << std::endl;
    world.AddBus();
    world.AddHeavyCar();
    world.AddMotorcycle();
    world.AddLightCar();
    PrintWorldInfo(world);

    std::cout << "Remove some transports" << std::endl;
    auto transports = world.GetTransports();
    int toRemove = 4;
    for (auto it = transports.begin(); it != transports.end() && toRemove > 0; it++, toRemove--)
    {
        world.RemoveTransport(*it);
    }
    PrintWorldInfo(world);

    std::cout << "Save world to file world.txt" << std::endl;
    world.SaveToFile("world.txt");

    std::cout << "**Navigator**" << std::endl;
    Position testPosition(400, 400);
    auto closestOnRoad = Navigator::Instance().FindClosestPositionOnRoad(testPosition, 1);
    std::cout << "Closest point on road for " << PositionAsString(testPosition) << " is " << PositionAsString(closestOnRoad) << std::endl;

    auto startPoint = Navigator::Instance().FindClosestPositionOnRoad(Position(50,200), 1);
    auto destinationPoint = Navigator::Instance().FindClosestPositionOnRoad(Position(350,350), 1);
    auto lightCarPath = Navigator::Instance().CalculatePathToDestination(startPoint, destinationPoint, 2000);
    auto heavyCarPath = Navigator::Instance().CalculatePathToDestination(startPoint, destinationPoint, 20000);
    double lightCarPathLength = 0;
    double heavyCarPathLength = 0;

    std::cout << "Closest way from " << PositionAsString(startPoint) << " to " << PositionAsString(destinationPoint) << std::endl;
    std::cout << "For light car is: ";
    for (int i = 0; i < lightCarPath.size(); i++)
    {
        std::cout << PositionAsString(lightCarPath[i]);
        if(i < lightCarPath.size() - 1)
            lightCarPathLength += MyMath::Distance(lightCarPath[i], lightCarPath[i + 1]);
    }
    std::cout << std::endl;

    std::cout << "For heavy car is: ";
    for (int i = 0; i < heavyCarPath.size(); i++)
    {
        std::cout << PositionAsString(heavyCarPath[i]);
        if (i < heavyCarPath.size() - 1)
            heavyCarPathLength += MyMath::Distance(heavyCarPath[i], heavyCarPath[i + 1]);
    }
    std::cout << std::endl;

    std::cout << "Light way distance :" << lightCarPathLength << std::endl;
    std::cout << "Heavy way distance :" << heavyCarPathLength << std::endl;
}
