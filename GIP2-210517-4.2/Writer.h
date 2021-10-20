#pragma once

#include "Printable.h"
#include "Graph.h"
#include <iomanip>

class Writer : public Printable
{
public:
	std::vector<std::vector<float>> matrix;
	Graph* graph;
	Writer(Graph* g) : graph{ g }, matrix{ g->matrix } {};
	virtual std::string toString() const;
};

