#pragma once

#include "Writer.h"

class Graphviz : public Writer
{
public:
	Graphviz(Graph* g) : Writer{ g }, nodes_{ g->nodes_ } {};
	std::string toString() const;
private:
	std::vector<Node*> nodes_;
};

