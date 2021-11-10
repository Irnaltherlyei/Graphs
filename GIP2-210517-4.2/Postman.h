#pragma once

#include "Djikstra.h"
#include "FloydWarshall.h"
#include "Graphviz.h"
#include <iomanip>
#include <algorithm>
#include <stack>
#include "Graph.h"
#include <queue>

class Postman
{
public:
	Postman(Graph* g) : graph{ g } {
		postman();
	};
private:
	Graph* graph;
	void postman();
	std::vector<std::vector<std::pair<size_t, size_t>>> pairing(std::vector<size_t> vertices, std::vector<std::pair<size_t, size_t>> list);
	bool isComplete(Graph*, std::vector<size_t> visited);
	std::vector<size_t> fleury(Graph* graph, size_t startVertex = 0);
	std::vector<size_t> hierholzer(Graph* graph, size_t startVertex = 0);
	std::vector<size_t> cycle(Graph* graph, size_t current);
	std::vector<size_t> eulerianPath(Graph* graph, size_t oddVertex);
};

