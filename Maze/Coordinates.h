#ifndef __COORDINATES__

#define __COORDINATES__

class Coordinates
{
private:
	int _x;
	int _y;
public:
	Coordinates(int x, int y);

	Coordinates();

	Coordinates(const Coordinates& coord);

	Coordinates operator+(const Coordinates& coord);

	bool operator==(const Coordinates& coord);
	
	void operator=(const Coordinates& coord);

	bool IsError();

	int GetX(void) const;

	int GetY(void) const;

};

#endif