#ifndef _COORDINATE_H_
#define _COORDINATE_H_

#include <vector>

class Coordinate
{
	private:
		char row;
		int col;
	public:
		Coordinate(char r = 'A', int c = 0);
		char getRow();
		int getColumn();
		Coordinate getLeft();
		Coordinate getRight();
		Coordinate getUp();
		Coordinate getDown();
		Coordinate getLeft(int i);
		Coordinate getRight(int i);
		Coordinate getUp(int i);
		Coordinate getDown(int i);
		bool isSameCoordinate(Coordinate c);
		bool isGoal();
};

#endif