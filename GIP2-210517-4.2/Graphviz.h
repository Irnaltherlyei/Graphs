#pragma once

#include "Writer.h"

class Graphviz : public Writer
{
public:
	Graphviz(Graph* g) : Writer{ g }, nodes_{ g->nodes_ }, edges_{ g->edges_ } {};
	std::string toString() const;
private:
	std::vector<Node*> nodes_;
	std::vector<std::vector<float>> edges_;
};

