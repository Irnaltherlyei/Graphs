#include "Writer.h"
std::string Writer::toString() const
{
    std::stringstream ss;
    for (auto i : graph->nodes_) {
        for (auto j : graph->nodes_) {
            ss << std::setw(5);
            if (i != j && graph->areConnected(i, j)) {
                std::vector<std::vector<float>> edges = graph->getEdges(i, j);
                if (edges.size() > 1) {
                    ss << std::setw(edges.size()) <<edges.size() << '*';
                }
                ss << graph->getEdges(i, j).front()[2] << " ";
            }
            else {
                ss << 0 << " ";
            }
        }
        ss << std::endl;
    }
    return ss.str();
}