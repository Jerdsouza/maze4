// Maze.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <cassert>
#include "Coordinates.h"
#include "Pixel.h"
#include "Maze.h"
#include <cassert>
#include <vector>

using namespace std;


int main()
{
	/************************************/
	/*          Test 1                  */
	/************************************/

	cout << endl << "/*          Test 1                  */" << endl;
	
	vector<vector<int>> grid =
	{
		{1, 2, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1},
		{1, 0, 0, 3, 1, 1}
	};


	// positive tests
	Maze myMaze(2, grid);
	if (myMaze.LoadMaze() == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze.SolveMaze();
	assert(myMaze.GetErrorCode() == ErrorNum::NoError);



	/************************************/
	/*          Test 2                  */
	/************************************/

	cout << endl << "/*          Test 2                  */" << endl;
	vector<vector<int>> grid1 =
	{
		{1, 2, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 3, 1},
	};

	// positive tests
	Maze myMaze1(2, grid1);
	if (myMaze1.LoadMaze() == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze1.SolveMaze();
	assert(myMaze1.GetErrorCode() == ErrorNum::NoError);


	/************************************/
	/*          Test 3                  */
	/************************************/

	cout << endl << "/*          Test 3                  */" << endl;
	vector<vector<int>> grid2 =
	{
		{2, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 3, 1},
	};

	// positive tests
	Maze myMaze2(2, grid2);
	if (myMaze2.LoadMaze() == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze2.SolveMaze();
	assert(myMaze2.GetErrorCode() == ErrorNum::NoError);
	

	/************************************/
	/*          Test 4                  */
	/************************************/

	cout << endl << "/*          Test 4                  */" << endl;
	vector<vector<int>> grid3 =
	{
		{1, 2, 1, 1, 1, 1},
		{1, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1},
		{1, 1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1, 1},
	};

	// negative tests
	Maze myMaze3(2, grid3);
	if (myMaze3.LoadMaze() == false)
	{
		// If load fails exit
		return 0;
	}
	myMaze3.SolveMaze();
	assert(myMaze3.GetErrorCode() == ErrorNum::NoTargetCell);

	return 0;
}
