#pragma once

#include "Writer.h"

class EdgeTable : public Writer
{
public:
	EdgeTable(Graph* g) : Writer{ g }, nodes_{ g->nodes_ } {};
	std::string toString() const;
private:
	std::vector<Node*> nodes_;
};

