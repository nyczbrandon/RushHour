#ifndef _NODE_H_
#define _NODE_H_

#include <vector>
#include "boardstate.hh"

class Node
{
	private:
		BoardState boardState;
		Node* parent;
		std::vector<Node*> children;
		int depth;
		int fcost;
		int heuristic();
	public:
		Node(Node* p, BoardState board = BoardState(), int depth = 0);
		BoardState getBoardState();
		Node* getParent();
		int getDepth() const;
		int getFCost() const;
		std::vector<Node*> getChildren();
		std::vector<Node*> getChilds();
		void generateChildren();
		bool isGoal();
		std::string toString();
};

#endif