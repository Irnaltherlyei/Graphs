#pragma once

#include "Writer.h"
#include <iomanip>
#include <algorithm>

class FloydWarshall : public Writer
{
public:
	FloydWarshall(Graph* g, std::pair<std::vector<std::vector<size_t>>, std::vector<std::vector<size_t>>>* pair = nullptr) : Writer(g), graph{ g } {
		floydWarshall(pair);
	};
	std::string toString() const;
private:
	Graph* graph;
	std::vector<std::vector<size_t>> floydWarshallMatrix;
	std::vector<std::vector<size_t>> prev;
	void floydWarshall(std::pair<std::vector<std::vector<size_t>>, std::vector<std::vector<size_t>>>* pair = nullptr);
};

