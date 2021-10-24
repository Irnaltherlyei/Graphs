#pragma once

#include "Node.h"

class FastNode : public Node
{
public:
	FastNode(std::string name, int index, float x, float y) : Node{ name, index, x, y} {}
	std::string toString() const;
};

