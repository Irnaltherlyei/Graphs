#pragma once

#include <vector>
#include "Node.h"

class Graph
{
public:
	std::vector<std::vector<float>> matrix;
	Graph(int vertices) : matrix(vertices, std::vector<float>(vertices, 0)) {}
	void addNode(Node* node);
	void connectNodes(std::string node1, std::string node2, float weight = 1.0f);
	void connectNodes(int node1, int node2, float weight = 1.0f);
	unsigned int countEdges(std::string node);
	unsigned int countEdges(int node);
	std::vector<Node*> nodes_;
	bool areConnected(std::string node1, std::string node2);
};

