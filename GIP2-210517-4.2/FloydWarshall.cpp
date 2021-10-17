#include "FloydWarshall.h"

std::string FloydWarshall::toString() const
{
	std::stringstream ss;
	for (auto v : floydWarshallMatrix) {
		for (auto u : v) {
			if (u == std::numeric_limits<std::size_t>::max()) {
				ss << std::setw(2) << "--" << ' ';
			}
			else {
				ss << std::setw(2) << u << ' ';
			}
		}
		ss << std::endl;
	}
	ss << std::endl;
	for (auto v : prev) {
		for (auto u : v) {
			if (u == std::numeric_limits<std::size_t>::max()) {
				ss << std::setw(2) << "--" << ' ';
			}
			else {
				ss << std::setw(2) << u << ' ';
			}
		}
		ss << std::endl;
	}
	return ss.str();
}

void FloydWarshall::floydWarshall()
{
	floydWarshallMatrix = std::vector<std::vector<size_t>>( graph->matrix.size(), std::vector<size_t>(graph->matrix.size(), std::numeric_limits<std::size_t>::max()));
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
	}

	int countNodes = graph->matrix.size();
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
}
