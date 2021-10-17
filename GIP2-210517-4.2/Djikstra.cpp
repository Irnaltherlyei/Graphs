#include "Djikstra.h"

std::string Djikstra::toString() const
{
	std::stringstream ss;
	for (auto u : length) {
		if (u == std::numeric_limits<std::size_t>::max()) {
			ss << std::setw(2) << "--" << ' ';
		}
		else {
			ss << std::setw(2) << u << ' ';
		}	
	}
	ss << std::endl << std::endl;
	for (auto u : prev) {
		if (u == std::numeric_limits<std::size_t>::max()) {
			ss << std::setw(2) << "--" << ' ';
		}
		else {
			ss << std::setw(2) << u << ' ';
		}
	}
	ss << std::endl;
	return ss.str();
}

void Djikstra::djikstra(unsigned int vertex)
{
	for (int i = 0; i < graph->nodes_.size(); i++) {
		length.push_back(std::numeric_limits<std::size_t>::max());
		prev.push_back(std::numeric_limits<std::size_t>::max());
	}
	length[vertex] = 0;
	prev[vertex] = std::numeric_limits<std::size_t>::max();
	std::vector<size_t> to_visit{ vertex };
	std::vector<size_t> visited;

	while (!to_visit.empty()) {
		int index_min_value = to_be_processed(to_visit);
		for (int i = 0; i < graph->matrix.size(); i++) {
			if (graph->matrix[index_min_value][i] == 1) {
				if (std::find(visited.begin(), visited.end(), index_min_value) == visited.end()) {
					to_visit.push_back(i);
				}
				if (length[i] > length[index_min_value] + 1) {
					length[i] = length[index_min_value] + 1;
					prev[i] = index_min_value;
				}				
			}
		}
		
		auto it = std::find(to_visit.begin(), to_visit.end(), index_min_value);
		if (it != to_visit.end()) {
			visited.push_back(index_min_value);
			to_visit.erase(it);
		}
		std::sort(to_visit.begin(), to_visit.end());
		
		/*std::cout << "Current Node: " << index_min_value << std::endl;
		std::cout << "to_visit: ";
		for (auto a : to_visit) {
				std::cout << a << ' ';
		}
		std::cout << std::endl;
		std::cout << "visited: ";
		for (auto a : visited) {
			std::cout << a << ' ';
		}
		std::cout << std::endl;*/
	}
}

int Djikstra::getMinIndex(std::vector<size_t>& v)
{
	auto it = std::min_element(v.begin(), v.end());
	if (v.end() != it) {
		return std::distance(v.begin(), it);
	}
}

std::size_t Djikstra::to_be_processed(std::vector<size_t> i)
{
	std::vector<size_t> v;
	std::vector<size_t>& values = length;
	const auto compare = [&values](const std::size_t& a, const std::size_t& b)
	{
		return values.at(a) < values.at(b);
	};
	for (auto index : i) {
		auto it = std::min_element(i.begin(), i.end(), compare);
		v.push_back(*it);
		i.erase(it);
	}
	return v.front();
}


