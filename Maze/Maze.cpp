#include "Maze.h"
#include <iostream>

using namespace std;

const Coordinates Maze::Edelta(0, 1);
const Coordinates Maze::Wdelta(0, -1);
const Coordinates Maze::Ndelta(-1, 0);
const Coordinates Maze::Sdelta(1, 0);


// Find the startcell in the grid
// Assuming that the start cell will always be in the first row 
Coordinates Maze::findstartcellinmaze(void)
{
	for (int i = 0; i < _numOfCols; i++)
	{
		if (_grid[0][i] == _startID)
		{
			cout << "Found start cell in maze at: " << 0 << " ," << i << endl;
			return Coordinates(0, i);
		}

	}
	handleerror(ErrorNum::NoStartCell);
	// did not find the start cell in maze
	return Coordinates(- 1, -1);
}

void Maze::handleerror(ErrorNum error)
{
	switch (error)
	{
	case ErrorNum::NoStartCell:
		cout << "Did not find a start cell in the Maze grid" << endl;
		break;
	case ErrorNum::PathNotFound:
		cout << "Could not find a path to the target"  << endl;
		break;
	case ErrorNum::NoLeftwall:
		cout << "Did not find a wall for hallway maze" << endl;
		break;
	case ErrorNum::ReachedWall:
		cout << "Reached a wall" << endl;
		break;
	case ErrorNum::NoTargetCell:
		cout << "No Target cell found." << endl;
		break;
	case ErrorNum::DeadEnd:
		cout << "Reached a Dead end" << endl;
		break;
	default:
		assert(false);
		break;
	}
	_error = error;
}

bool Maze::testcellvalue(Coordinates coord, int testval)
{
	//if (_grid[(coord.GetX() * _numOfCols) + coord.GetY()] == testval)
	if (_grid[coord.GetX()][coord.GetY()] == testval)
	{
		return true;
	}

	return false;

}

bool Maze::isycoordoutofbounds(Coordinates coord)
{
	if(coord.GetY() > (_numOfCols - 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Maze::iswallcell(Coordinates coord)
{
	if (isycoordoutofbounds(coord))
	{
		return true;
	}
	else
	{
		if (testcellvalue(coord, 1))
		{
			return true;
		}
	}
	return false;
}

bool Maze::istargetcell(Coordinates coord)
{
	if (testcellvalue(coord, _targetID))
	{
		return true;
	}
	return false;
}

bool Maze::iscellinboundary(Coordinates coord)
{
	if ((coord.GetX() < _numOfRows) && (coord.GetY() < _numOfCols))
	{
		return true;
	}
	return false;
}

bool Maze::iscellempty(Coordinates coord)
{
	if (iswallcell(coord) == false && iscellinboundary(coord))
	{
		return true;
	}	
	return false;
}


Coordinates Maze::getleftcell(void)
{
	Coordinates coord;
	switch (_pixel.GetDirection())
	{
	case E:
		coord = _pixel.GetCoordinates() + Ndelta;
		break;
	case W:
		coord = _pixel.GetCoordinates() + Sdelta;
		break;
	case N:
		coord = _pixel.GetCoordinates() + Wdelta;
		break;
	case S:
		coord = _pixel.GetCoordinates() + Edelta;
		break;
	default:
		assert(false);
		break;
	}
	return coord;
}

Coordinates Maze::getfrontcell(void)
{
	Coordinates coord;
	switch (_pixel.GetDirection())
	{
	case E:
		coord = _pixel.GetCoordinates() + Edelta;
		break;
	case W:
		coord = _pixel.GetCoordinates() + Wdelta;
		break;
	case N:
		coord = _pixel.GetCoordinates() + Ndelta;
		break;
	case S:
		coord = _pixel.GetCoordinates() + Sdelta;
		break;
	default:
		assert(false);
		break;
	}
	return coord;
}

void Maze::rotateccw(void)
{
	switch (_pixel.GetDirection())
	{
	case E:
		_pixel.SetDirection(N);
		break;
	case W:
		_pixel.SetDirection(S);
		break;
	case N:
		_pixel.SetDirection(W);
		break;
	case S:
		_pixel.SetDirection(E);
		break;
	default:
		assert(false);
		break;
	}
}

void Maze::rotatecw(void)
{
	switch (_pixel.GetDirection())
	{
	case E:
		_pixel.SetDirection(S);
		break;
	case W:
		_pixel.SetDirection(N);
		break;
	case N:
		_pixel.SetDirection(E);
		break;
	case S:
		_pixel.SetDirection(W);
		break;
	default:
		assert(false);
		break;
	}
}


void Maze::moveforward(void)
{
	Coordinates coord = getfrontcell();
	_pixel.SetCoordinates(coord);
}


// Loads the maze with the gridArray to be solved and the num of rows and cols.
// Find the start cell and set up the pixel to the start cell.
bool Maze::LoadMaze( )
{
	/*
	bool result = true;
	if (numOfRows == 0)
	{
		handleerror(ErrorNum::NumOfRowsIsZero);
		result = false;
	}

	if (numOfCols == 0)
	{
		handleerror(ErrorNum::NumOfColsIsZero);
		result = false;
	}

	if (gridArray == NULL)
	{
		handleerror(ErrorNum::MazeGrid);
		result = false;
	}
	*/

	//if (result == true)
	//{
		//_grid = gridArray;
	bool result = true;
	_numOfRows = _grid.size();
	_numOfCols = _grid[0].size();

	_size = _numOfRows * _numOfCols;
	_startCell = findstartcellinmaze();

	if (_startCell.IsError())
	{
		result = false;
	}
	else
	{
		_pixel.SetCoordinates(_startCell);
	}
	//}
	return result;
}

Coordinates Maze::GetStartCell(void) const
{
	return _startCell;
}


list<Coordinates> Maze::GetPath()
{
	return _path;
}

ErrorNum Maze::GetErrorCode(void)
{
	return _error;
}

list<Coordinates> Maze::findhallwaypath()
{	
	_error = ErrorNum::NoError;
	Coordinates leftcell = getleftcell();
	Coordinates frontcell = getfrontcell();

	while (istargetcell(_pixel.GetCoordinates()) == false)
	{
		if (iswallcell(leftcell) == false)
		{
			handleerror(ErrorNum::NoLeftwall);
			break;
		}
		else if (iscellempty(frontcell))
		{
			if (istargetcell(frontcell))
			{
				moveforward();
				_path.push_front(frontcell);
				cout << _pixel.GetCoordinates().GetX() << ", " << _pixel.GetCoordinates().GetY() << endl;
				continue;
			}
			else if (iswallcell(frontcell))
			{
				handleerror(ErrorNum::NoTargetCell);
				break;
			}
			else
			{
				moveforward();
				_path.push_front(frontcell);
				cout << _pixel.GetCoordinates().GetX() << ", " << _pixel.GetCoordinates().GetY() << endl;
			}
		}
		else
		{
			if (iscellinboundary(frontcell) == false)
			{
				handleerror(ErrorNum::ReachedWall);
			}
			else if (testcellvalue(frontcell, 1))
			{
				handleerror(ErrorNum::ReachedWall);
			}
			else
			{
				// should not reach here
				assert(false);
			}
			break;
		}

		leftcell = getleftcell();
		frontcell = getfrontcell();

	}

	return _path;
	
}

list<Coordinates> Maze::SolveMaze()
{

	while (istargetcell(_pixel.GetCoordinates()) == false)
	{
		findhallwaypath();

		switch (GetErrorCode())
		{
		case ErrorNum::ReachedWall:
		{
			rotatecw();
			Coordinates frontcell = getfrontcell();
			_error = ErrorNum::NoError;
			if (testcellvalue(frontcell, 1))
			{
				handleerror(ErrorNum::DeadEnd);
				handleerror(ErrorNum::NoTargetCell);
				return _path;
			}
		}
		break;
		case ErrorNum::NoLeftwall:
		{
			rotateccw();
			moveforward();
			_path.push_front(_pixel.GetCoordinates());
			cout << _pixel.GetCoordinates().GetX() << ", " << _pixel.GetCoordinates().GetY() << endl;
			_error = ErrorNum::NoError;
		}
		break;
		case ErrorNum::NoTargetCell:
		{
			return _path;
		}
		break;
		case ErrorNum::NoError:
		{
			// do nothing
		}
		break;
		default:
			assert(false);
		break;
		}
	}

	return _path;

}

