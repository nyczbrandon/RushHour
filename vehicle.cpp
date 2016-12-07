#include "vehicle.hh"

Vehicle::Vehicle(std::string s)
{
	name = s.at(0);
	if (name == 'B')
		length = 3;
	else
		length = 2;
	direction = s.at(1);
	generateVehicle(Coordinate(s.at(2), s.at(3) - '0'));
}

Vehicle::Vehicle(char n, int l, char d, Coordinate c)
{
	name = n;
	length = l;
	direction = d;
	generateVehicle(c);
}

char Vehicle::getName()
{
	return name;
}

std::vector<Coordinate> Vehicle::getPositions()
{
	return positions;
}

int Vehicle::distanceFromGoal()
{
	return 6 - positions.back().getColumn();
}

void Vehicle::generateVehicle(Coordinate c)
{
	if (direction == 'H')
		for (int i = 0; i < length; i++)
			positions.push_back(c.getRight(i));
	else
		for (int i = 0; i < length; i++)
			positions.push_back(c.getDown(i));
}

bool Vehicle::canMoveForward(std::vector<Vehicle> vehicles)
{
	Coordinate c;
	if (direction == 'H')
	{
		if (positions.back().getColumn() == 6)
			return false;
		c = positions.back().getRight();
	}
	else
	{
		if (positions.back().getRow() == 'F')
			return false;
		c = positions.back().getDown();
	}
	for (Vehicle v : vehicles)
			for (Coordinate pos : v.positions)
				if (c.isSameCoordinate(pos))
						return false;
	return true;
}

bool Vehicle::canMoveBackward(std::vector<Vehicle> vehicles)
{
	Coordinate c;
	if (direction == 'H')
	{
		if (positions.front().getColumn() == 1)
			return false;
		c = positions.front().getLeft();
	}
	else
	{
		if (positions.front().getRow() == 'A')
			return false; 
		c = positions.front().getUp();
	}
	for (Vehicle v : vehicles)
		for (Coordinate pos : v.positions)
			if (c.isSameCoordinate(pos))
				return false;
	return true;
}

Vehicle Vehicle::getForwardMove()
{
	Coordinate c;
	if (direction == 'H')
		c = positions.front().getRight();
	else
		c = positions.front().getDown();
	return Vehicle(name, length, direction, c);
}

Vehicle Vehicle::getBackwardMove()
{
	Coordinate c;
	if (direction == 'H')
		c = positions.front().getLeft();
	else
		c = positions.front().getUp();
	return Vehicle(name, length, direction, c);
}

bool Vehicle::isSameVehicle(Vehicle v)
{
	if (name == v.name && direction == v.direction && positions.front().isSameCoordinate(v.positions.front()))
		return true;
	return false;
}

bool Vehicle::isGoal()
{
	if (name == 'I' && positions.front().isGoal())
		return true;
	return false;
}

std::string Vehicle::toString()
{
	std::string s = "";
	s += name;
	s += direction;
	s += positions.front().getRow();
	s += '0' + positions.front().getColumn();
	return s;
}
