#pragma once

#include "Writer.h"
#include <iomanip>
#include <algorithm>

class Djikstra : public Writer
{
public:
	Djikstra(Graph* g, int vertex, std::pair<std::vector<size_t>, std::vector<size_t>>* pair = nullptr) : Writer(g), graph{g} {
		djikstra(vertex, pair);
	};
	std::string toString() const;
private:
	Graph* graph;
	std::vector<size_t> length;
	std::vector<size_t> prev;
	void djikstra(unsigned int vertex, std::pair<std::vector<size_t>, std::vector<size_t>>* pair = nullptr);
	int getMinIndex(std::vector<size_t>& v);
	std::size_t to_be_processed(std::vector<size_t> i);
};

