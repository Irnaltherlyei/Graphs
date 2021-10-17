#pragma once

#include "Writer.h"

class AdjacencyMatrixWriter : public Writer
{
public: 
	AdjacencyMatrixWriter(Graph* g) : Writer{ g } {};
	std::string toString() const;
};

