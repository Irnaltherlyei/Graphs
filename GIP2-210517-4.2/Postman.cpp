#include "Postman.h"

void Postman::postman()
{
	// Djikstra
	std::pair<std::vector<size_t>, std::vector<size_t>> pair;
	new Djikstra(graph, 0, &pair);

	for (auto u : pair.first) {
		std::cout << std::setw(3) << u;
	}
	std::cout << std::endl;
	for (auto u : pair.second) {
		std::cout << std::setw(3) << u;
	}

	// Adjacency Matrix
	std::vector<std::vector<float>> matrix;
	matrix = graph->matrix;
	for (auto u : matrix) {
		for (auto v : u) {
			std::cout << std::setw(3) << v;
		}
		std::cout << std::endl;
	}

	//// Count edges
	//for (auto u : graph->nodes_) {
	//	std::cout << std::setw(3) << graph->countEdges(u->name_);
	//}
	//std::cout << std::endl;

	//// Check if graph is complete
	//std::cout << isComplete() << std::endl;

	// If graph is not complete return
	if (not isComplete(graph)) {
		return;
	}

	// Find vertices with odd degree
	std::vector<Node*> odd;
	for (auto vertex : graph->nodes_) {
		if (graph->countEdges(vertex->name_) % 2) {
			odd.push_back(vertex);
		}
	}

	// If vertices with odd degree are found
	if (not odd.empty()) {
		Graph o(odd.size());
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
