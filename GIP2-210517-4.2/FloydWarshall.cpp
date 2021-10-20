#include "FloydWarshall.h"

std::string FloydWarshall::toString() const
{
	std::stringstream ss;
	for (auto v : floydWarshallMatrix) {
		for (auto u : v) {
			if (u == std::numeric_limits<std::size_t>::max()) {
				ss << std::setw(3) << "--" << ' ';
			}
			else {
				ss << std::setw(3) << u << ' ';
			}
		}
		ss << std::endl;
	}
	ss << std::endl;
	for (auto v : prev) {
		for (auto u : v) {
			if (u == std::numeric_limits<std::size_t>::max()) {
				ss << std::setw(3) << "--" << ' ';
			}
			else {
				ss << std::setw(3) << u << ' ';
			}
		}
		ss << std::endl;
	}
	return ss.str();
}

void FloydWarshall::floydWarshall(std::pair<std::vector<std::vector<size_t>>, std::vector<std::vector<size_t>>>* pair)
{
	/*floydWarshallMatrix = std::vector<std::vector<size_t>>( graph->matrix.size(), std::vector<size_t>(graph->matrix.size(), std::numeric_limits<std::size_t>::max()));
	prev = std::vector<std::vector<size_t>>(graph->matrix.size(), std::vector<size_t>(graph->matrix.size(), std::numeric_limits<std::size_t>::max()));
	for (int i = 0; i < graph->matrix.size(); i++) {
		for (int j = 0; j < graph->matrix.size(); j++) {
			if (i == j) {
				floydWarshallMatrix[i][j] = 0;
			}
			else if(graph->matrix[i][j] == 0) {
				floydWarshallMatrix[i][j] = std::numeric_limits<std::size_t>::max();
			}
			else if (graph->matrix[i][j] > 0) {
				floydWarshallMatrix[i][j] = graph->matrix[i][j];
				prev[i][j] = i;
			}
			else {
				prev[i][j] = std::numeric_limits<std::size_t>::max();
			}
		}
	}*/

	floydWarshallMatrix = std::vector<std::vector<size_t>>(graph->nodes_.size(), std::vector<size_t>(graph->nodes_.size(), std::numeric_limits<std::size_t>::max()));
	prev = std::vector<std::vector<size_t>>(graph->nodes_.size(), std::vector<size_t>(graph->nodes_.size(), std::numeric_limits<std::size_t>::max()));
	for (int i = 0; i < graph->nodes_.size(); i++) {
		for (int j = 0; j < graph->nodes_.size(); j++) {
			if (i == j) {
				floydWarshallMatrix[i][j] = 0;
			}

			if (graph->getEdges(i, j).empty()) {
				continue;
			}
			size_t min_value = std::numeric_limits<size_t>::max();
			for (auto edge : graph->getEdges(i, j)) {
				if (edge[2] < min_value) {
					min_value = edge[2];
				}
			}

			if (min_value == 0) {
				floydWarshallMatrix[i][j] = std::numeric_limits<std::size_t>::max();
			}
			else if (min_value > 0) {
				floydWarshallMatrix[i][j] = min_value;
				prev[i][j] = i;
			}
			else {
				prev[i][j] = std::numeric_limits<std::size_t>::max();
			}
		}
	}

	int countNodes = graph->nodes_.size();
	for (int i = 0; i < countNodes; i++) {
		for (int j = 0; j < countNodes; j++) {
			for (int k = 0; k < countNodes; k++) {
				if (floydWarshallMatrix[j][k] > (floydWarshallMatrix[j][i] + floydWarshallMatrix[i][k])
					&& floydWarshallMatrix[j][i] != std::numeric_limits<std::size_t>::max()
					&& floydWarshallMatrix[i][k] != std::numeric_limits<std::size_t>::max()
					&& j != k) {
						prev[j][k] = prev[i][k];
						floydWarshallMatrix[j][k] = (floydWarshallMatrix[j][i] + floydWarshallMatrix[i][k]);
				}
			}
		}
	}
	if (pair != nullptr) {
		*pair = std::pair<std::vector<std::vector<size_t>>, std::vector<std::vector<size_t>>>(floydWarshallMatrix, prev);
	}
}
