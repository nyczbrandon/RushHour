#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <string>
#include "coordinate.hh"

class Vehicle
{
	private:
		char name;
		int length;
		char direction;
		std::vector<Coordinate> positions;
		void generateVehicle(Coordinate c);
	public:
		Vehicle(std::string s);
		Vehicle(char n, int l, char d, Coordinate c);
		char getName();
		std::vector<Coordinate> getPositions();
		int distanceFromGoal();
		bool canMoveForward(std::vector<Vehicle> vehicles);
		bool canMoveBackward(std::vector<Vehicle> vehicles);
		Vehicle getForwardMove();
		Vehicle getBackwardMove();
		bool isSameVehicle(Vehicle v);
		bool isGoal();
		std::string toString();
};

#endif