#include "Graphviz.h"

std::string Graphviz::toString() const
{
    std::stringstream ss;
    ss << "graph {" << std::endl;
    for (auto node : nodes_) {
        ss << "  " << node->toString() << std::endl;
    }

    // ss << new EdgeTable(graph); possible but whitespaces are not present in the EdgeTable Class
    // Using matrix
    /*for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[i][j] != 0.0f && i <= j) {
                ss << "  " << nodes_[i]->name_ << " -- " << nodes_[j]->name_ << " " 
                   << "[label=\"" << matrix[i][j] << "\"]" << std::endl;
            }
        }
    }*/
    // Using edges_
    for (int i = 0; i < edges_.size(); i++) {
        if (edges_[i][2] != 0.0f) {
            ss << "  " << nodes_[edges_[i][0]]->name_ << " -- " << nodes_[edges_[i][1]]->name_ << " "
                << "[label=\"" << edges_[i][2] << "\"]" << std::endl;
        }
    }

    ss << "}" << std::endl;
    return ss.str();
}
