#pragma once

#include "Node.h"

class SlowNode : public Node
{
public:
	SlowNode(std::string name, float x, float y) : Node{ name, x, y } {}
	std::string toString() const;
};

