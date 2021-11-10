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

	if (odd.size() == 2) {
		// Euler path
		Graph copy = *graph;
		std::cout << "Eulerian path";
		for (auto v : eulerianPath(&copy, 4)) {
			std::cout << " -> " << graph->nodes_[v]->name_;
		}
		std::cout << std::endl;
		return;
	}
	// If vertices with odd degree are found
	if (not odd.empty()) {
		std::vector<size_t> vertices;
		for (auto vertex : odd) {
			vertices.push_back(vertex->index_);
		}

		// Find shortest path between all vertices
		std::pair<std::vector<std::vector<size_t>>, std::vector<std::vector<size_t>>> shortestPaths;
		new FloydWarshall(graph, &shortestPaths);
		
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

	// Euler cycle
	Graph copy = *graph;
	/*std::cout << "Fleury: Eulerian cycle";
	for (auto v : fleury(&copy, 0)) {
		std::cout << " -> " << graph->nodes_[v]->name_;
	}
	std::cout << std::endl;*/

	/*copy = *graph;
	std::cout << "Hierholzer: Eulerian cycle";
	for (auto v : hierholzer(&copy, 0)) {
		std::cout << " -> " << graph->nodes_[v]->name_;
	}
	std::cout << std::endl;*/

	// Graph with new edges
	std::cout << new Graphviz(&copy) << std::endl;
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

std::vector<size_t> Postman::fleury(Graph* graph, size_t startVertex)
{
	std::vector<size_t> euler;
	std::vector<size_t> visited;
	size_t current = startVertex;
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

std::vector<size_t> Postman::hierholzer(Graph* graph, size_t startVertex)
{
	std::vector<std::vector<size_t>> euler;
	size_t current = startVertex;
	// Get all cycles and store in euler.
	while (graph->edges_.size() != 0) {
		std::vector<size_t> tmp = cycle(graph, current);
		euler.push_back(tmp);
		for (auto n : tmp) {
			std::cout << graph->nodes_[n]->name_ << " ";
 		}
		std::cout << std::endl;
		
		if (graph->edges_.size() != 0) {
			current = graph->edges_.front()[0];
		}
		/*std::cout << " NEXT = " << current << " " << graph->nodes_[current]->name_ << " " << std::endl;
		std::cout << graph->edges_.size() << std::endl;
		std::cout << new Graphviz(graph) << std::endl;*/
	}
	while (euler.size() >= 2) {
		std::vector<size_t> tmp = euler.back();
		euler.pop_back();
		int first = tmp.front();

		std::vector<size_t> tmp2 = euler.back();
		euler.pop_back();
		auto it = std::find(tmp2.begin(), tmp2.end(), first);

		if (it != tmp2.end()) {
			int index = std::distance(tmp2.begin(), it);
			tmp2.erase(tmp2.begin() + index);
			tmp2.insert(tmp2.begin() + index, tmp.begin(), tmp.end());
			euler.push_back(tmp2);
		}
		else {
			euler.insert(euler.begin(), tmp2);
		}
		
	}
	return euler.front();
}

std::vector<size_t> Postman::cycle(Graph* graph, size_t startVertex)
{
	std::vector<size_t> cycle;
	size_t current = startVertex;
	cycle.push_back(current);

	while (!graph->edges_.empty()) {
		std::vector<size_t> neighbours = graph->getNeighbours(current);
		/*std::cout << std::endl;
		for (int i = 0; i < neighbours.size(); i++) {
			std::cout << neighbours[i] << " ";
		}
		std::cout << std::endl;*/

		for (auto next : neighbours) {
			graph->deleteEdge(current, next);
			//std::cout << "DELETE: " << current << " " << next << std::endl;
			if (next == startVertex || graph->getNeighbours(next).size() == 0) {
				//std::cout << graph->nodes_[next]->name_ << " ";
				cycle.push_back(next);
				return cycle;
			} else {
				//std::cout << graph->nodes_[current]->name_ << " ";
				cycle.push_back(next);
				current = next;
				break;
			}
		}
	}
	return cycle;
	//std::cout << std::endl;
}

std::vector<size_t> Postman::eulerianPath(Graph* graph, size_t oddVertex)
{
	std::vector<size_t> euler;
	std::stack<size_t> vertices;
	size_t current = oddVertex;
	vertices.push(oddVertex);
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
