#pragma once

#include "Node.h"

class FastNode : public Node
{
public:
	FastNode(std::string name, float x, float y) : Node{ name, x, y} {}
	std::string toString() const;
};

