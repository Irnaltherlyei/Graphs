#include "IncidencyMatrixWriter.h"

std::string IncidencyMatrixWriter::toString() const
{
    std::stringstream ss;
    for (auto v : inzidenzMatrix) {
        for (auto f : v) {
            ss << std::setw(3) << f << " ";
        }
        ss << std::endl;
    }
    return ss.str();
}

void IncidencyMatrixWriter::getIncidencyMatrix()
{
    for (int i = 0; i < graph->edges_.size(); i++) {
        inzidenzMatrix.push_back(std::vector<float>(graph->edges_.size(), 0));
    }
    for (int i = 0; i < graph->nodes_.size(); i++) {
        for (int j = 0; j < graph->edges_.size(); j++) {
            if (graph->edges_[j][0] == i || graph->edges_[j][1] == i) {
                inzidenzMatrix[i][j] = graph->edges_[j][2];
            }
        }
    }
}
