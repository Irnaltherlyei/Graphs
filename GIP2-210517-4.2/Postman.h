#pragma once

#include "Djikstra.h"
#include "FloydWarshall.h"
#include "Graphviz.h"
#include <iomanip>
#include <algorithm>

class Postman
{
public:
	Postman(Graph* g) : graph{ g } {
		postman();
	};
private:
	Graph* graph;
	void postman();
	bool isComplete(Graph*);
};

