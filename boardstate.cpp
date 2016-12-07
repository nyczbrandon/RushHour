#include "boardstate.hh"

BoardState::BoardState(std::vector<Vehicle> v)
{
	vehicles = v;
	hcost = heuristic();
}

std::vector<Vehicle> BoardState::getVehicles()
{
	return vehicles;
}

int BoardState::getHCost()
{
	return hcost;
}

std::vector<BoardState> BoardState::getLegalMoves()
{
	std::vector<BoardState> allLegalMoves;
	std::vector<Vehicle> legalBoard;
	for (Vehicle a : vehicles)
	{
		if (a.canMoveForward(vehicles))
		{
			legalBoard.clear();
			for (Vehicle b : vehicles)
			{
				if (b.isSameVehicle(a))
					legalBoard.push_back(a.getForwardMove());
				else
					legalBoard.push_back(b);
			}
			allLegalMoves.push_back(BoardState(legalBoard));
		}
		if (a.canMoveBackward(vehicles))
		{
			legalBoard.clear();
			for (Vehicle b : vehicles)
			{
				if (b.isSameVehicle(a))
					legalBoard.push_back(a.getBackwardMove());
				else
					legalBoard.push_back(b);
			}
			allLegalMoves.push_back(BoardState(legalBoard));
		}
	}
	return allLegalMoves;
}

int BoardState::heuristic()
{
	int value = 0;
	int distance = 0;
	Coordinate block('C', 6);
	for (Vehicle v : vehicles)
		if (v.getName() == 'I')
			value = v.distanceFromGoal();
	distance = value;
	for (int i = 0; i < distance; i++)
	{
		for (Vehicle v : vehicles)
			if (v.getName() != 'I')
				for (Coordinate c : v.getPositions())
					if (c.isSameCoordinate(block.getLeft(i)))
						value++;
	}
	return value;
}

bool BoardState::isGoal()
{
	for (Vehicle v : vehicles)
		if (v.isGoal())
			return true;
	return false;
}

bool BoardState::isSameBoard(BoardState b)
{
	bool found;
	for (Vehicle v : b.getVehicles())
	{
		found = false;
		for (Vehicle ve : vehicles)
			if (v.isSameVehicle(ve))
				found = true;
		if (!found)
			return false;
	}
	return true;
}

std::string BoardState::toString()
{
	std::string s = "";
	for (Vehicle v : vehicles)
	{
		s += " ";
		s += v.toString();
	}
	return s;
}