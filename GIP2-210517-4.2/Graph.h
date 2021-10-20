#pragma once

#include <vector>
#include "Node.h"

class Graph
{
public:
	std::vector<std::vector<float>> matrix;
	Graph(int vertices) : matrix(vertices, std::vector<float>(vertices, 0)) {}
	void addNode(Node* node);
	void connectNodes(Node* node1, Node* node2, float weight = 1.0f);
	void connectNodes(int node1, int node2, float weight = 1.0f);
	unsigned int countEdges(Node* node);
	unsigned int countEdges(int node);
	std::vector<std::vector<float>> getEdges(Node* node1, Node* node2);
	std::vector<std::vector<float>> getEdges(int index1, int index2);
	std::vector<Node*> nodes_;
	std::vector<std::vector<float>> edges_;
	bool areConnected(Node* node1, Node* node2);
	unsigned int getIndex(Node* node);
};

