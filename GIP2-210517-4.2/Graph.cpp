#include "Graph.h"
#include <sstream>

void Graph::addNode(Node* node)
{
    nodes_.push_back(node);
}

void Graph::connectNodes(std::string node1, std::string node2)
{
    int index1 = -1;
    int index2 = -1;
    for (int i = 0; i < nodes_.size(); i++) {
        if (nodes_[i]->name_ == node1) {
            index1 = i;
        } 
        else if (nodes_[i]->name_ == node2) {
            index2 = i;
        }
    }
    if (index1 >= 0 && index2 >= 0) {
        matrix[index1][index2] = 1.0f;
        matrix[index2][index1] = 1.0f;
    }
}

void Graph::connectNodes(int node1, int node2)
{
    if (node1 >= 0 && node2 >= 0 && node1 < matrix.size() && node2 < matrix.size()) {
        matrix[node1][node2] = 1.0f;
        matrix[node2][node1] = 1.0f;
    }
}

bool Graph::areConnected(std::string node1, std::string node2)
{
    int index1 = -1;
    int index2 = -1;
    for (int i = 0; i < nodes_.size(); i++) {
        if (nodes_[i]->name_ == node1) {
            index1 = i;
        }
        else if (nodes_[i]->name_ == node2) {
            index2 = i;
        }
    }
    if (index1 >= 0 && index2 >= 0 && matrix[index1][index2] == 1.0f) {
        return true;
    }
    return false;
}
