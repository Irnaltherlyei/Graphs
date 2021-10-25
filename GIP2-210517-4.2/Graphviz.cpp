#include "Graphviz.h"

std::string Graphviz::toString() const
{
    std::stringstream ss;
    ss << "graph {" << std::endl;
    for (auto node : nodes_) {
        ss << "  " << node->toString() << std::endl;
    }
    for (int i = 0; i < edges_.size(); i++) {
        if (edges_[i][2] != 0.0f) {
            ss << "  " << nodes_[edges_[i][0]]->name_ << " -- " << nodes_[edges_[i][1]]->name_ << " "
                << "[label=\"" << edges_[i][2] << "\"]" << std::endl;
        }
    }

    ss << "}" << std::endl;
    return ss.str();
}
