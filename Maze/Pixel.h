
#ifndef __PIXEL_H__
#define __PIXEL_H__


#include "Coordinates.h"


enum Direction { E = 0, S, W, N };

// Class representing the agent that will be moved in the Maze
class Pixel
{
private:
	Direction _dir;
	Coordinates _coordinates;
public:
	Pixel(Direction dir, Coordinates coordinates) :_dir(dir), _coordinates(coordinates)
	{
	}


	Pixel(const Pixel& pix);

	void SetCoordinates(Coordinates coord);

	Coordinates GetCoordinates();

	Direction GetDirection(void);

	void SetDirection(Direction dir);
};

#endif
