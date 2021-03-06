#pragma once

#include <vector>
#include "Node.h"

class Graph
{
public:
	std::vector<std::vector<float>> matrix;
	std::vector<Node*> nodes_;
	std::vector<std::vector<float>> edges_;		// Vector with vector [0] = node1 [1] = node2 [2] = weigth
	Graph(int vertices) : matrix(vertices, std::vector<float>(vertices, 0)) {}
	void addNode(Node* node);
	void addEdge(Node* node1, Node* node2, float weight = 1.0f);
	void addEdge(int node1, int node2, float weight = 1.0f);
	void deleteEdge(int index1, int index2);
	std::vector<std::vector<float>> getEdges(Node* node1, Node* node2);
	std::vector<std::vector<float>> getEdges(int index1, int index2);				
	bool areConnected(Node* node1, Node* node2);
	unsigned int getIndex(Node* node);
	std::vector<std::vector<float>> getEdges(int index);
	std::vector<size_t> getNeighbours(int index);
};

