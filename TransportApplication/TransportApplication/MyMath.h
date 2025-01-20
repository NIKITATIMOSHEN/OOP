#pragma once
#include <vector>
#include <list>

struct Position
{
public:
	Position() : Position(0, 0)
	{ }
	Position(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	double x;
	double y;
};

class MyMath
{
public:

	static double Distance(const Position pos1, const Position pos2)
	{
		return sqrt(pow(pos1.x - pos2.x, 2.0) + pow(pos1.y - pos2.y, 2));
	}
	static Position CalcVector(const Position a, const Position b)
	{
		return Position(b.x - a.x, b.y - a.y);
	}

	static Position CalcVectorNormalize(const Position& a, const Position& b) {
		double dist = Distance(a, b);
		return { (b.x - a.x) / dist, (b.y - a.y) / dist };
	}

	static bool IsPositionsEqual(Position pos1, Position pos2)
	{
		return pos1.x == pos2.x && pos1.y == pos2.y;
	}

	static int Next(int max) { return rand() % max; }
	static double NextDouble() { return static_cast<double>(rand()) / RAND_MAX; }
private:

};