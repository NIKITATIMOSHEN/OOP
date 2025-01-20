#include "Navigator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

Navigator::Navigator() {
    ReadRoadsFromFile();
    // Зв'язуємо сусідні ділянки доріг між собою
    for (int i = 0; i < Roads.size(); i++)
    {
        Road* road = &Roads[i];
        for (int j = 0; j < Roads.size(); j++)
        {
            if (i == j)
                continue;
            if (MyMath::IsPositionsEqual(road->end, Roads[j].start))
                road->nextRoads.push_back(&Roads[j]);
            if (MyMath::IsPositionsEqual(road->end, Roads[j].end))
                road->nextRoads.push_back(&Roads[j]);

            if (MyMath::IsPositionsEqual(road->start, Roads[j].start))
                road->prevRoads.push_back(&Roads[j]);
            if (MyMath::IsPositionsEqual(road->start, Roads[j].end))
                road->prevRoads.push_back(&Roads[j]);
        }
    }

    ReadBusSchedulesFromFile();
}


Position Navigator::FindClosestPositionOnRoad(Position position, double carWeight) 
{
    std::vector<Road> validRoads;
    for (const Road& road : Roads) 
    {
        if (road.maxWeightKg > carWeight)
            validRoads.push_back(road);
    }

    Road closestRoad = validRoads[0];
    double closestLength = MyMath::Distance(position, closestRoad.start);
    Position closestPosition = closestRoad.start;

    for (const Road& road : validRoads) 
    {
        Position roadVector = MyMath::CalcVector(road.start, road.end);
        for (float i = 0; i <= 1.04; i += 0.05f) {
            Position pointOnRoad = Position(road.start.x + roadVector.x * i, road.start.y + roadVector.y * i);
            double length = MyMath::Distance(position, pointOnRoad);
            if (length < closestLength) {
                closestLength = length;
                closestRoad = road;
                closestPosition = pointOnRoad;
            }
        }
    }
    return closestPosition;
}

const Road* Navigator::FindClosestRoad(Position position, double carWeight) 
{
    std::vector<const Road*> validRoads;
    for (const Road& road : Roads)
    {
        if (road.maxWeightKg > carWeight)
            validRoads.push_back(&road);
    }

    const Road* closestRoad = validRoads[0];
    double closestLength = MyMath::Distance(position, closestRoad->start);

    for (const Road* road : validRoads)
    {
        Position roadVector = MyMath::CalcVector(road->start, road->end);
        for (float i = 0; i <= 1.04; i += 0.05f)
        {
            Position pointOnRoad = Position(road->start.x + roadVector.x * i, road->start.y + roadVector.y * i);
            double length = MyMath::Distance(position, pointOnRoad);
            if (length < closestLength)
            {
                closestLength = length;
                closestRoad = road;
            }
        }
    }
    return closestRoad;
}

std::vector<Position> Navigator::CalculatePathToDestination(Position start, Position destination, double carWeight) 
{
    std::vector<Road> validRoads;
    for (const Road& road : Roads)
    {
        if (road.maxWeightKg > carWeight)
            validRoads.push_back(road);
    }
    std::vector<Position> result;
    const Road* startRoad = FindClosestRoad(start, carWeight);
    const Road* destinationRoad = FindClosestRoad(destination, carWeight);
    if (startRoad == destinationRoad)
    {
        result.push_back(start);
        result.push_back(destination);
        return result;
    }

    double minLength = std::numeric_limits<double>::max();
    std::vector<const Road*> minWay;
    std::vector<const Road*> currentWay;

    //Пошук коротшого шляху
    CalculateWay(startRoad, destinationRoad, currentWay, carWeight, 0, minLength, minWay);

    result.push_back(start);
    for (int i = 0; i < minWay.size() - 1; i++)
    {
        bool isNextRoad = false;

        for (const Road* road : minWay[i]->nextRoads)
        {
            if (road == minWay[i + 1])
            {
                isNextRoad = true;
                break;
            }
        }

        if (isNextRoad)
            result.push_back(minWay[i]->end);
        else
            result.push_back(minWay[i]->start);
    }
    result.push_back(destination);
    return result;
}

double Navigator::CalculateWay(const Road* testRoad, const Road* endRoad,
    std::vector<const Road*>& currentWay, double carWeight,
    double currentLength, double& minLength, std::vector<const Road*>& minWay) 
{
    currentLength = currentLength + MyMath::Distance(testRoad->start, testRoad->end);
    if (currentLength >= minLength)
        return -1;

    for (const Road* road : currentWay)
    {
        if (road == testRoad)
            return -1;
    }

    currentWay.push_back(testRoad);

    if (testRoad == endRoad)
    {
        minWay = currentWay;
        minLength = currentLength;
        currentWay.pop_back();
        return currentLength;
    }

    std::vector<const Road*> validPrevRoads;
    for (const Road* road : testRoad->prevRoads)
    {
        if (road->maxWeightKg >= carWeight)
            validPrevRoads.push_back(road);
    }

    std::vector<const Road*> validNextRoads;
    for (const Road* road : testRoad->nextRoads)
    {
        if (road->maxWeightKg >= carWeight)
            validNextRoads.push_back(road);
    }

    double shortestLength = -1;

    for (const Road* prevRoad : validPrevRoads)
    {
        double wayLength = CalculateWay(prevRoad, endRoad, currentWay, carWeight,
            currentLength, minLength, minWay);
        if (wayLength != -1 && (shortestLength == -1 || wayLength < shortestLength))
        {
            shortestLength = wayLength;
        }
    }

    for (const Road* nextRoad : validNextRoads)
    {
        double wayLength = CalculateWay(nextRoad, endRoad, currentWay, carWeight,
            currentLength, minLength, minWay);
        if (wayLength != -1 && (shortestLength == -1 || wayLength < shortestLength))
        {
            shortestLength = wayLength;
        }
    }

    currentWay.pop_back();
    return shortestLength;
}

void Navigator::ReadRoadsFromFile()
{
    std::ifstream inputFile("roads.txt");
    std::string line;

    while (std::getline(inputFile, line)) 
    {
        std::vector<int> numbers;
        std::stringstream ss(line);
        std::string numberStr;
        while (std::getline(ss, numberStr, ',')) 
        {
            int number = std::stoi(numberStr);
            numbers.push_back(number);
        }
        Roads.push_back(Road(Position(numbers[0], numbers[1]), Position(numbers[2], numbers[3]), numbers[4]));
    }

    inputFile.close();
}

void Navigator::ReadBusSchedulesFromFile()
{
    std::ifstream inputFile("schedules.txt");
    std::string line;

    while (std::getline(inputFile, line))
    {
        std::vector<int> numbers; 
        std::stringstream ss(line);
        std::string numberStr;
        while (std::getline(ss, numberStr, ','))
        {
            int number = std::stoi(numberStr);
            numbers.push_back(number);
        }
        std::vector<Position> schedulePath;
        for (int i = 0; i < numbers.size() -1; i = i + 2)
        {
            
            schedulePath.push_back(Position(numbers[i], numbers[i+1]));
        }
        std::vector<Position> fixedPath;
        for (int i = 0; i < schedulePath.size(); i++)
        {
            fixedPath.push_back(FindClosestPositionOnRoad(schedulePath[i], 7000));
        }

        BusSchedules.push_back(fixedPath);
    }

    inputFile.close();
}
