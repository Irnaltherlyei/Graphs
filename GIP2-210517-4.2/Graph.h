#pragma once

#include <vector>
#include "Node.h"

class Graph
{
public:
	std::vector<std::vector<float>> matrix;
	Graph(int vertices) : matrix(vertices, std::vector<float>(vertices, 0)) {}
	void addNode(Node* node);
	void connectNodes(std::string node1, std::string node2);
	void connectNodes(int node1, int node2);
	std::vector<Node*> nodes_;
	bool areConnected(std::string node1, std::string node2);
};

