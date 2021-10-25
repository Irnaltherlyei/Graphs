#include "Postman.h"

void Postman::postman()
{
	#pragma region TESTING

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
		std::cout << std::setw(3) << graph->getNeighbours(u->index_);
	}
	std::cout << std::endl;*/

	// Check if graph is complete
	//std::cout << isComplete() << std::endl;
	
	#pragma endregion

	// If graph is not complete return
	if (not isComplete(graph, std::vector<size_t>())) {
		return;
	}

	// Find vertices with odd degree
	std::vector<Node*> odd;
	for (auto vertex : graph->nodes_) {
		if (graph->getNeighbours(vertex->index_).size() % 2) {
			odd.push_back(vertex);
		}
	}

	// If vertices with odd degree are found
	if (not odd.empty()) {
		Graph oddVertices(odd.size());
		for (auto vertex : odd) {
			oddVertices.addNode(vertex);
		}

		// Find shortest path between all vertices
		std::pair<std::vector<std::vector<size_t>>, std::vector<std::vector<size_t>>> shortestPaths;
		new FloydWarshall(graph, &shortestPaths);

		// Every possible pairings
		std::vector<size_t> vertices{0, 3, 4, 6};
		std::vector<std::vector<std::pair<size_t, size_t>>> pairings = pairing(vertices, std::vector<std::pair<size_t, size_t>>());
		/*int i = 0;
		for (auto v : pairings) {
			i++;
			for (auto p : v) {
				std::cout << '(' << p.first << ' ' << p.second << ')';
			}
			std::cout << std::endl;
		}
		std::cout <<"Possible Pairings: " << i << std::endl;*/
		
		// Get pairing with minimal cost
		size_t minCost = std::numeric_limits<std::size_t>::max();
		size_t currentCost = 0;
		std::vector<std::pair<size_t, size_t>> bestPair;
		for (auto vec : pairings) {
			for (auto pair : vec) {
				currentCost += shortestPaths.first[pair.first][pair.second];
			}
			if (currentCost < minCost) {
				minCost = currentCost;
				bestPair = vec;
			}
			currentCost = 0;
		}

		// Get new edges to add
		std::vector<std::vector<size_t>> newEdges;
		for (auto pair : bestPair) {
			newEdges.push_back(std::vector<size_t>());

			size_t from = pair.first;
			size_t to = pair.second;

			newEdges.back().push_back(to);

			while (from != to) {
				to = shortestPaths.second[from][to];
				newEdges.back().push_back(to);
			}
 		}

		// Add new edges
		for (auto vec : newEdges) {
			for (int i = 0; i < vec.size() - 1; i++) {
				graph->addEdge(vec[i], vec[i + 1], graph->getEdges(vec[i], vec[i + 1]).front()[2]);
			}
		}
	}
	Graph copy = *graph;
	std::cout << "Eulerian cycle";
	for (auto v : eulerianCycle(&copy)) {
		std::cout << " -> " << graph->nodes_[v]->name_;
	}
	std::cout << std::endl;

	copy = *graph;
	std::cout << "Eulerian path";
	for (auto v : eulerianPath(&copy)) {
		std::cout << " -> " << graph->nodes_[v]->name_;
	}
	std::cout << std::endl;
}

std::vector<std::vector<std::pair<size_t, size_t>>> Postman::pairing(std::vector<size_t> vertices, std::vector<std::pair<size_t, size_t>> list)
{
	std::vector<std::vector<std::pair<size_t, size_t>>> pairs;
	if (vertices.empty()) {
		pairs.push_back(list);
		return pairs;
	}
	else {
		auto it = std::min_element(vertices.begin(), vertices.end());
		int i = *it;
		vertices.erase(it);
		for (int index = 0; index < vertices.size(); index++) {
			int j = vertices[index];
			vertices.erase(vertices.begin() + index);

			std::pair<size_t, size_t> pair(i, j);
			list.push_back(pair);

			std::vector<std::vector<std::pair<size_t, size_t>>> r = pairing(vertices, list);

			list.erase(list.end() - 1);

			pairs.insert(pairs.end(), r.begin(), r.end());

			vertices.insert(vertices.begin(), j);
		}
	}
	return pairs;
}

bool Postman::isComplete(Graph* g, std::vector<size_t> visited)
{
	std::pair<std::vector<std::vector<size_t>>, std::vector<std::vector<size_t>>> pair;
	new FloydWarshall(g, &pair);
	for (int i = 0; i < pair.first.size(); i++) {
		for (int j = 0; j < pair.first[i].size(); j++) {
			if (std::find(visited.begin(), visited.end(), i) != visited.end()
				|| std::find(visited.begin(), visited.end(), j) != visited.end()) {
				// Do nothing - do not return false
			} 
			else if (pair.first[i][j] == std::numeric_limits<std::size_t>::max()) {
				return false;
			}
		}
	}
	return true;
}

std::vector<size_t> Postman::eulerianCycle(Graph* graph)
{
	std::vector<size_t> euler;
	std::vector<size_t> visited;
	size_t current = 0;
	while (!graph->edges_.empty()) {
		std::vector<size_t> neighbours = graph->getNeighbours(current);
		for (auto next : neighbours) {
			graph->deleteEdge(current, next);
			if (graph->getNeighbours(current).size() == 0) {
				visited.push_back(current);
			}
			if (isComplete(graph, visited)) {
				euler.push_back(current);
				current = next;
				break;
			}
			else {
				graph->addEdge(current, next);
			}
		}
	}
	euler.push_back(current);
	return euler;
}

std::vector<size_t> Postman::eulerianPath(Graph* graph)
{
	std::vector<size_t> euler;
	std::stack<size_t> vertices;
	size_t current = 0;
	vertices.push(0);
	while (!vertices.empty()) {
		size_t current = vertices.top();
		std::vector<size_t> neighbours = graph->getNeighbours(current);
		if (neighbours.size() == 0) {
			euler.push_back(current);
			vertices.pop();
		}
		else {
			size_t next = neighbours.front();
			graph->deleteEdge(current, next);
			vertices.push(next);
		}
	}
	return euler;
}
