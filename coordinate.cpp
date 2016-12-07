#include "coordinate.hh"

Coordinate::Coordinate(char r, int c)
{
	row = r;
	col = c;
}

char Coordinate::getRow()
{
	return row;
}

int Coordinate::getColumn()
{
	return col;
}

Coordinate Coordinate::getLeft()
{
	return Coordinate(row, col - 1);
}

Coordinate Coordinate::getRight()
{
	return Coordinate(row, col + 1);
}

Coordinate Coordinate::getUp()
{
	return Coordinate(row - 1, col);
}

Coordinate Coordinate::getDown()
{
	return Coordinate(row + 1, col);
}

Coordinate Coordinate::getLeft(int i)
{
	return Coordinate(row, col - i);
}

Coordinate Coordinate::getRight(int i)
{
	return Coordinate(row, col + i);
}

Coordinate Coordinate::getUp(int i)
{
	return Coordinate(row - i, col);
}

Coordinate Coordinate::getDown(int i)
{
	return Coordinate(row + i, col);
}

bool Coordinate::isSameCoordinate(Coordinate c)
{
	if (row == c.row && col == c.col)
		return true;
	return false;
}

bool Coordinate::isGoal()
{
	if (row == 'C' && col == 5)
		return true;
	return false;
}