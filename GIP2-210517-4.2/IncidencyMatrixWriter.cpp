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
    int countEdges = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[i][j] > 0.0f && i <= j) {
                countEdges++;
            }
        }
    }
    for (int i = 0; i < matrix.size(); i++) {
        inzidenzMatrix.push_back(std::vector<float>(countEdges, 0));
    }
    int edge = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[i][j] > 0.0f && i <= j) {
                inzidenzMatrix[i][edge] = inzidenzMatrix[j][edge] = matrix[i][j];
                edge++;
                if (edge == countEdges) {
                    break;
                }
            }
        }
    }
}
