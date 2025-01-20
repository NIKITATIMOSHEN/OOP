#pragma once
#include "MyMath.h"

struct Road
{
public:
	Road(Position start, Position end, double maxWeightKg = double::MaxValue)
	{
		this->start = start;
		this->end = end;
		this->maxWeightKg = maxWeightKg;
	}
	Position start;
	Position end;
	double maxWeightKg;
	//Вектор вказівників на ділянки доріг що контактують з точною end
	std::vector<const Road*> nextRoads;
	//Вектор вказівників на ділянки доріг що контактують з точною start
	std::vector<const Road*> prevRoads;
};

class Navigator 
{
private:
	Navigator();

	void ReadRoadsFromFile();
	void ReadBusSchedulesFromFile();
	~Navigator()
	{}

	Navigator(const Navigator&) = delete;
	Navigator& operator=(const Navigator&) = delete;

	std::vector<std::vector<Position>> BusSchedules;
	std::vector<Road> Roads;

	double CalculateWay(const Road* testRoad, const Road* endRoad, std::vector<const Road*>& currentWay,
		double carWeight, double currentLength, double& minLength, std::vector<const Road*>& minWay);
public:
	const Position GasStation = Position(270, 165);
	static Navigator& Instance() 
	{
		static Navigator singleton;
		return singleton;
	}
	inline const std::vector<Road>& GetRoads() const
	{
		return Roads;
	}

	inline std::vector<std::vector<Position>> GetBusSchedules() const
	{
		return BusSchedules;
	}

	Position FindClosestPositionOnRoad(Position position, double carWeight);
	const Road* FindClosestRoad(Position position, double carWeight);
	std::vector<Position> CalculatePathToDestination(Position start, Position destination, double carWeight);
};