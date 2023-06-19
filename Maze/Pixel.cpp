#include "Pixel.h"


Pixel::Pixel(const Pixel& pix)
{
	_dir = pix._dir;
	_coordinates = pix._coordinates;
}

void Pixel::SetCoordinates(Coordinates coord)
{
	_coordinates = coord;
}

Coordinates Pixel::GetCoordinates()
{
	return _coordinates;
}

Direction Pixel::GetDirection(void)
{
	return _dir;
}

void Pixel::SetDirection(Direction dir)
{
	_dir = dir;
}


