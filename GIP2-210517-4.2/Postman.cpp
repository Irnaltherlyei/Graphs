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
		//std::cout << vertex->name_ << " " << graph->countEdges(vertex) << std::endl;
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
		
		//std::cout << oddVertices.nodes_.size() << std::endl;

		/*std::vector<std::vector<int>> res = pairOdd(std::vector<int>{1,2,3,4,5,6});
		for (auto v : res) {
			for (auto p : v) {
				std::cout << p;
			}
			std::cout << std::endl;
		}*/
		std::vector<int> vertices{ 1, 2, 3, 4, 5, 6};
		/*std::vector<std::vector<int>> a = aaa(vertices, std::vector<int>());
		int i = 0;
		for (auto v : a) {
			i++;
			for (auto p : v) {
				std::cout << p;
			}
			std::cout << std::endl;
		}
		std::cout << i << std::endl;*/
		std::vector<std::vector<std::pair<int, int>>> a = pairing(vertices, std::vector<std::pair<int, int>>());
		for (auto v : a) {
			for (auto p : v) {
				std::cout << '(' << p.first << ' ' << p.second << ')';
			}
			std::cout << std::endl;
		}
		/*int count = vertices.size();
		int i = 0;
		for (auto v : a) {
			for (auto p : v) {
				std::cout << p << " ";
				i++;
				if (i % count == 0) {
					std::cout << std::endl;
				}
			}
		}
		std::cout << std::endl;

		std::cout <<"Possible Pairings: " << i / count << std::endl;*/
	}
}

std::string Postman::pairOdd(std::vector<int> vertices, int ov)
{	
	std::string result;
	std::stringstream ss;
	if (vertices.empty()) {
		return "\n";
	}
	else {
		auto it = std::min_element(vertices.begin(), vertices.end());
		int i = *it;
		vertices.erase(it);
		for (int index = 0; index < vertices.size(); index++) {
			int j = vertices[index];
			std::vector<int> tmp = vertices;
			tmp.erase(tmp.begin() + index);
			ss << "(" << i << " " << j << ")" << pairOdd(tmp, 0);
			result = ss.str();
		}
		return result;
		/*Node* v1 = vertices.front();
		vertices.erase(vertices.begin());
		for (auto v2 : vertices) {
			vertices.erase(vertices.begin());
			ss << "(" << v1->name_ << " " << v2->name_ << ")" << pairOdd(result, vertices);
			result = ss.str();
			return result;
		}*/
	}
}

std::vector<std::vector<int>> Postman::pairOdd(std::vector<int> vertices)
{	
	std::vector<std::vector<int>> pairs;
	if (vertices.empty()) {
		return std::vector<std::vector<int>>();
	}
	else {
		auto it = std::min_element(vertices.begin(), vertices.end());
		int i = *it;
		vertices.erase(it);
		for (int index = 0; index < vertices.size(); index++) {
			int j = vertices[index];
			vertices.erase(vertices.begin() + index);
			pairs.push_back(std::vector<int>{i, j});
			std::vector<std::vector<int>> returnValue = pairOdd(vertices);
			pairs.insert(pairs.end(), returnValue.begin(), returnValue.end());
			vertices.insert(vertices.begin(), j);
		}
		vertices.insert(vertices.begin(), i);
	}
	return pairs;
}

std::vector<std::vector<int>> Postman::aaa(std::vector<int> vertices, int pairfirst, int pairsecond)
{	
	std::vector<std::vector<int>> pairs;
	if (vertices.empty()) {
		pairs.push_back(std::vector<int>{pairfirst, pairsecond});
		return pairs;
	}
	else {
		auto it = std::min_element(vertices.begin(), vertices.end());
		int i = *it;
		vertices.erase(it);
		for (int index = 0; index < vertices.size(); index++) {
			int j = vertices[index];
			vertices.erase(vertices.begin() + index);
			
			if (pairfirst != 0 && pairsecond != 0) {
				pairs.push_back(std::vector<int>{pairfirst, pairsecond});
			}

			std::vector<std::vector<int>> returnValue = aaa(vertices, i, j);
			pairs.insert(pairs.end(), returnValue.begin(), returnValue.end());

			vertices.insert(vertices.begin(), j);
		}
		vertices.insert(vertices.begin(), i);
	}
	return pairs;
}

std::vector<std::vector<int>> Postman::aaa(std::vector<int> vertices, std::vector<int> list, int in1, int in2)
{
	std::vector<std::vector<int>> pairs;
	if (vertices.empty()) {
		list.push_back(in1);
		list.push_back(in2);
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

			if (in1 != 0 && in2 != 0) {
				list.push_back(in1);
				list.push_back(in2);
			}

			std::vector<std::vector<int>> returnValue = aaa(vertices, list, i, j);
			
			pairs.insert(pairs.end(), returnValue.begin(), returnValue.end());

			vertices.insert(vertices.begin(), j);
		}
		vertices.insert(vertices.begin(), i);
	}
	return pairs;
}

std::vector<std::vector<int>> Postman::aaa(std::vector<int> vertices, std::vector<int> list)
{
	std::vector<std::vector<int>> pairs;
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

			list.push_back(i);
			list.push_back(j);

			std::vector<std::vector<int>> r = aaa(vertices, list);

			list.erase(list.end() - 1);
			list.erase(list.end() - 1);

			pairs.insert(pairs.end(), r.begin(), r.end());

			vertices.insert(vertices.begin(), j);
		}
		vertices.insert(vertices.begin(), i);
	}
	return pairs;
}

std::vector<std::vector<std::pair<int, int>>> Postman::pairing(std::vector<int> vertices, std::vector<std::pair<int, int>> list)
{
	std::vector<std::vector<std::pair<int, int>>> pairs;
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

			std::pair<int, int> pair(i, j);
			list.push_back(pair);

			std::vector<std::vector<std::pair<int, int>>> r = pairing(vertices, list);

			list.erase(list.end() - 1);

			pairs.insert(pairs.end(), r.begin(), r.end());

			vertices.insert(vertices.begin(), j);
		}
	}
	return pairs;
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