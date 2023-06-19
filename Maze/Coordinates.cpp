#include "Coordinates.h"
Coordinates::Coordinates(int x, int y) : _x(x), _y(y)
{}

Coordinates::Coordinates()
{
	_x = 0;
	_y = 0;
}

Coordinates::Coordinates(const Coordinates& coord)
{
	_x = coord._x;
	_y = coord._y;
}

Coordinates Coordinates::operator+(const Coordinates& coord)
{
	return Coordinates((_x + coord._x), (_y + coord._y));
}

bool Coordinates::operator==(const Coordinates& coord)
{
	if ((_x == coord._x) && (_y == coord._y))
	{
		return true;
	}
	return false;
}

void Coordinates::operator=(const Coordinates& coord)
{
	_x = coord._x;
	_y = coord._y;
}

bool Coordinates::IsError()
{
	if ((_x == -1) || (_y == -1))
	{
		return true;
	}
	return false;
}

int Coordinates::GetX(void) const
{
	return _x;
}

int Coordinates::GetY(void) const
{
	return _y;
}