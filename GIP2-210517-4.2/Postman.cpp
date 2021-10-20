#include "Postman.h"

void Postman::postman()
{
	// SOME TESTING

	// Djikstra
	/*std::pair<std::vector<size_t>, std::vector<size_t>> pair;
	new Djikstra(graph, 0, &pair);

	for (auto u : pair.first) {
		std::cout << std::setw(3) << u;
	}
	std::cout << std::endl;
	for (auto u : pair.second) {
		std::cout << std::setw(3) << u;
	}*/

	// Floyd
	/*std::pair<std::vector<std::vector<size_t>>, std::vector<std::vector<size_t>>> pair;
	new FloydWarshall(graph, &pair);

	for (auto u : pair.first) {
		for (auto v : u) {
			std::cout << std::setw(3) << v;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (auto u : pair.second) {
		for (auto v : u) {
			if (v == std::numeric_limits<std::size_t>::max()) {
				std::cout << std::setw(3) << "--";

			}
			else {
				std::cout << std::setw(3) << v;
			}
		}
		std::cout << std::endl;
	}*/

	// Adjacency Matrix
	/*std::vector<std::vector<float>> matrix;
	matrix = graph->matrix;
	for (auto u : matrix) {
		for (auto v : u) {
			std::cout << std::setw(3) << v;
		}
		std::cout << std::endl;
	}*/

	// Count edges
	/*for (auto u : graph->nodes_) {
		std::cout << std::setw(3) << graph->countEdges(u->name_);
	}
	std::cout << std::endl;*/

	// Check if graph is complete
	//std::cout << isComplete() << std::endl;

	// POSTMAN PROBLEM

	// If graph is not complete return
	if (not isComplete(graph)) {
		return;
	}

	// Find vertices with odd degree
	std::vector<Node*> odd;
	for (auto vertex : graph->nodes_) {
		std::cout << vertex->name_ << " " << graph->countEdges(vertex) << std::endl;
		if (graph->countEdges(vertex) % 2) {
			odd.push_back(vertex);
		}
	}

	// If vertices with odd degree are found
	if (not odd.empty()) {
		Graph oddVertices(odd.size());
		for (auto vertex : odd) {
			oddVertices.addNode(vertex);
		}

		// Create new Graph with odd vertices
		for (int i = 0; i < odd.size(); i++) {
			for (int j = i + 1; j < odd.size(); j++) {
				oddVertices.connectNodes(i, j);
			}
		}
		//std::cout << new Graphviz(&oddVertices) << std::endl;

		// Find shortest path between all vertices
		std::pair<std::vector<std::vector<size_t>>, std::vector<std::vector<size_t>>> shortestPaths;
		new FloydWarshall(graph, &shortestPaths);

		// CHECK ALL PAIRINGS AND FIND PAIRINGS WITH LEAST COST
		for (int i = 0; i < oddVertices.nodes_.size(); i++) {
			for (int j = 0; j < oddVertices.nodes_.size(); j++) {
				if (i != j && i < j) {
					std::cout << i << " " << j << " " << shortestPaths.first[i][j] << std::endl;
				}
			}
		}

		// GET THOSE EDGES AND ADD TO GRAPH
	}
}

bool Postman::isComplete(Graph* g)
{
	std::pair<std::vector<size_t>, std::vector<size_t>> pair;
	new Djikstra(g, 0, &pair);
	for (auto cost : pair.first) {
		if (cost == std::numeric_limits<std::size_t>::max()) {
			return false;
		}
	}
	return true;
}
