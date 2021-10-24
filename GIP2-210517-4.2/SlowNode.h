#pragma once

#include "Node.h"

class SlowNode : public Node
{
public:
	SlowNode(std::string name, int index, float x, float y) : Node{ name, index, x, y } {}
	std::string toString() const;
};

