#include "node.hh"

Node::Node(Node* p, BoardState board, int i)
{
	parent = p;
	boardState = board;
	depth = i;
	fcost = heuristic();
}

BoardState Node::getBoardState()
{
	return boardState;
}

Node* Node::getParent()
{
	return parent;
}

int Node::getDepth() const
{
	return depth;
}

int Node::getFCost() const
{
	return fcost;
}

std::vector<Node*> Node::getChildren()
{
	return children;
}

std::vector<Node*> Node::getChilds()
{
	std::vector<Node*> childs;
	for (BoardState b : boardState.getLegalMoves())
		childs.push_back(new Node(this, b, depth + 1));
	return childs;
}


int Node::heuristic()
{
	return depth + boardState.getHCost();
}

void Node::generateChildren()
{
	for (BoardState b : boardState.getLegalMoves())
		children.push_back(new Node(this, b, depth + 1));
}

bool Node::isGoal()
{
	return boardState.isGoal();
}

std::string Node::toString()
{
	std::string s = "";
	for (int i = 0; i < depth; i++)
		s += "-";
	s += boardState.toString();
	return s;
}