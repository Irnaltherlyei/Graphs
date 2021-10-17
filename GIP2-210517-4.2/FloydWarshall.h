#pragma once

#include "Writer.h"
#include <iomanip>
#include <algorithm>

class FloydWarshall : public Writer
{
public:
	FloydWarshall(Graph* g) : Writer(g), graph{ g } {	
		floydWarshall();
	};
	std::string toString() const;
private:
	Graph* graph;
	std::vector<std::vector<size_t>> floydWarshallMatrix;
	std::vector<std::vector<size_t>> prev;
	void floydWarshall();
};

