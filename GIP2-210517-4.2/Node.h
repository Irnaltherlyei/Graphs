#pragma once

#include "Printable.h"

class Node : public Printable
{
public:
	Node(std::string name, int index, float x, float y) : name_{ name }, index_{ index }, x_{ x }, y_{ y } {}
	virtual std::string toString() const;

	std::string name_;
	int index_;
	float x_;
	float y_;
};

