#pragma once

#include "Printable.h"

class Node : public Printable
{
public:
	Node(std::string name, float x, float y) : name_{ name }, x_{ x }, y_{y} {}
	virtual std::string toString() const;

	std::string name_;
	float x_;
	float y_;
};

