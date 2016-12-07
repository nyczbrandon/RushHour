#include <stddef.h>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
#include <iostream>
#include "node.hh"

int visited;

struct NodeComparator
{
	bool operator()(const Node* l, const Node* r) const
	{
		if (l -> getFCost() == r -> getFCost())
			return l -> getDepth() > r -> getDepth();
		return l -> getFCost() < r -> getFCost();
	}
};


BoardState* dls(BoardState* node, int depth, int limit)
{
	for (int i = 0; i < limit - depth; i++)
		std::cout << "-";
	visited++;
	std::cout << visited << std::endl;
	std::cout << node -> toString();
	std::cout << std::endl;
	if (depth == 0 && node -> isGoal())
	{
		return node;
	}
	else if (depth > 0)
		for (BoardState child : node -> getLegalMoves())
		{
			BoardState* found = dls(new BoardState(child.getVehicles()), depth - 1, limit);
			if (found != nullptr)
				return found;
		}
	return nullptr;
}

bool dls(BoardState node, int depth)
{
	visited++;
	std::cout << visited << std::endl;
	if (depth == 0 && node.isGoal())
	{
		return true;
	}
	else if (depth > 0)
		for (BoardState child : node.getLegalMoves())
		{
			bool found = dls(BoardState(child.getVehicles()), depth - 1);
			if (found)
				return true;
		}
	return false;
}

bool iddfs(BoardState root)
{
	int depth = 0;
	visited = 0;
	while(true)
	{
		bool found = dls(root, depth);
		if (found)
		{
			std::cout << depth << std::endl;
			std::cout << visited << std::endl;
			return true;
		}
		depth++;
	}
	return false;
}

BoardState* iddfs(BoardState* root, int i)
{
	int depth = 0;
	while(depth <= i)
	{
		BoardState* found = dls(root, depth, depth);
		if (found != nullptr)
		{
			std::cout << depth << std::endl;
			return found;
		}
		depth++;
	}
	return nullptr;
}

bool inClosedSet(std::vector<BoardState> cSet, Node* child)
{
	for (BoardState b : cSet)
		if ((child -> getBoardState()).isSameBoard(b))
			return true;
	return false;
}

bool inOpenSet(std::multiset<Node*, NodeComparator> openSet, Node* child)
{
	std::multiset<Node*, NodeComparator>::iterator it;
	for (it = openSet.begin(); it != openSet.end(); it++)
	{
		if (((*it) -> getBoardState()).isSameBoard(child -> getBoardState()))
			return true;
	}
	return false;
}

std::deque<BoardState> smastar(BoardState start)
{
	std::multiset<Node*, NodeComparator> openSet;
	std::multiset<Node*, NodeComparator>::iterator it;
	std::vector<BoardState> closedSet;
	std::deque<BoardState> path;
	Node* root = new Node(nullptr, start, 0);
	Node* top;
	visited = 0;
	openSet.insert(root);
	while (!openSet.empty())
	{
		it = openSet.begin();
		top = *it;
		std::cout << "Fcost: ";
		std::cout << top -> getFCost();
		std::cout << ", Depth: ";
		std::cout << top -> getDepth();
		std::cout << "    ";
		std::cout << visited << std::endl;
		visited++;
		if (top -> isGoal())
		{
			while (top -> getParent() != nullptr)
			{
				path.push_front(top -> getBoardState());
				top = top -> getParent();
			}
			return path;
		}
		openSet.erase(it);
		closedSet.push_back(top -> getBoardState());
		top -> generateChildren();
		for (Node* child : top -> getChildren())
		{
			if (inClosedSet(closedSet, child))
				continue;
			if (openSet.size() == 50)
				openSet.erase(std::prev(openSet.end()));
			if (!inOpenSet(openSet, child))
				openSet.insert(child);
		}
	}
	return path;
}


int main(int argc, char* argv[])
{
	std::vector<std::string> easy1 = {"IHC3", "CVA3", "BHB4", "CVC5", "CVE5"};
	std::vector<std::string> easy5 = {"IHC4", "CVA4", "BVA6", "CVD4", "CHE5"};
	std::vector<std::string> easy9 = {"IHC4", "CVE3", "CVD5", "BHD1", "BVC6", "BHF4"};
	std::vector<std::string> medium11 = {"IHC1", "CVC3", "CHA5", "CHB5", "CVC6", "CVE6", "BHA2", "BHE1"};
	std::vector<Vehicle> vehicles1;
	std::vector<Vehicle> vehicles5;
	std::vector<Vehicle> vehicles9;
	std::vector<Vehicle> vehicles11;
	std::deque<BoardState> easy1star;
	std::deque<BoardState> easy5star;
	std::deque<BoardState> easy9star;
	std::deque<BoardState> medium11star;
	BoardState root1;
	BoardState root5;
	BoardState root9;
	BoardState root11;
	for (int i = 0; i < easy1.size(); i++)
		vehicles1.push_back(Vehicle(easy1.at(i)));
	for (int i = 0; i< easy5.size(); i++)
		vehicles5.push_back(Vehicle(easy5.at(i)));
	for (int i = 0; i < easy9.size(); i++)
		vehicles9.push_back(Vehicle(easy9.at(i)));
	for (int i = 0; i < medium11.size(); i++)
		vehicles11.push_back(Vehicle(medium11.at(i)));
	root1 = BoardState(vehicles1);
	root5 = BoardState(vehicles5);
	root9 = BoardState(vehicles9);
	root11 = BoardState(vehicles11);
	std::cout << "Answer 2" << std::endl;
	iddfs(&root1, 3);
	std::cout << visited << std::endl;
	std::cout << "Answer 3" << std::endl;
	iddfs(root1);
	iddfs(root5);
	std::cout << visited << std::endl; 
	easy1star = smastar(root1);
	easy5star = smastar(root5);
	easy9star = smastar(root9);
	medium11star = smastar(root11);
	for (BoardState b : easy1star)
	{
		std::cout << "(";
		for (Vehicle v : b.getVehicles())
		{
			std::cout << v.toString();
			std::cout << " ";
		}
		std::cout << ") ";
	}
	return 0;
}	






