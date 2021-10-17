#pragma once

#include "Printable.h"
#include "Graph.h"

class Writer : public Printable
{
public:
	std::vector<std::vector<float>> matrix;
	Writer(Graph* g) : matrix{ g->matrix } {};
	virtual std::string toString() const;
};

