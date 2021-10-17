#include "Graphviz.h"

std::string Graphviz::toString() const
{
    std::stringstream ss;
    ss << "graph {" << std::endl;
    for (auto node : nodes_) {
        ss << "  " << node->toString() << std::endl;
    }

    // ss << new EdgeTable(graph); possible but whitespaces are not present in the EdgeTable Class
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[i][j] == 1.0f && i <= j) {
                ss << "  " << nodes_[i]->name_ << " -- " << nodes_[j]->name_ << std::endl;
            }
        }
    }

    ss << "}" << std::endl;
    return ss.str();
}
