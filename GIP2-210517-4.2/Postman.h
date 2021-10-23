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
	std::string pairOdd(std::vector<int> vertices, int ov);
	std::vector<std::vector<int>> pairOdd(std::vector<int> vertices);
	std::vector<std::vector<int>> aaa(std::vector<int> vertices, int index1, int index2);
	std::vector<std::vector<int>> aaa(std::vector<int> vertices, std::vector<int> list, int in1, int in2);
	std::vector<std::vector<int>> aaa(std::vector<int> vertices, std::vector<int> list);
	std::vector<std::vector<std::pair<int, int>>> pairing(std::vector<int> vertices, std::vector<std::pair<int, int>> list);
	bool isComplete(Graph*);
};

