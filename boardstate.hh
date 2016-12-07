#ifndef _BOARDSTATE_H_
#define _BOARDSTATE_H_

#include "vehicle.hh"

class BoardState
{
	private:
		std::vector<Vehicle> vehicles;
		int hcost;
		int heuristic();
	public:
		BoardState(std::vector<Vehicle> v = std::vector<Vehicle>());
		std::vector<Vehicle> getVehicles();
		int getHCost();
		std::vector<BoardState> getLegalMoves();
		bool isGoal();
		bool isSameBoard(BoardState b);
		std::string toString();
};

#endif