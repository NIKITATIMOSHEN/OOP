#pragma once

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