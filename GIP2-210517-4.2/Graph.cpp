#include "Graph.h"
#include <sstream>

void Graph::addNode(Node* node)
{
    nodes_.push_back(node);
}

void Graph::addEdge(Node* node1, Node* node2, float weight)
{
    int index1 = getIndex(node1);
    int index2 = getIndex(node2);
    if (index1 == -1 or index2 == -1) return;

    matrix[index1][index2] = weight;
    matrix[index2][index1] = weight;
    edges_.push_back(std::vector<float>{(float)index1, (float)index2, weight});
}

void Graph::addEdge(int node1, int node2, float weight)
{
    if (node1 >= 0 && node2 >= 0 && node1 < nodes_.size() && node2 < nodes_.size()) {
        matrix[node1][node2] = weight;
        matrix[node2][node1] = weight;
        edges_.push_back(std::vector<float>{(float)node1, (float)node2, weight});
    }
}

std::vector<std::vector<float>> Graph::getEdges(Node* node1, Node* node2)
{   
    std::vector<std::vector<float>> edges;

    int index1 = getIndex(node1);
    int index2 = getIndex(node2);
    if (index1 == -1 || index2 == -1) return edges;

    for (auto edge : edges_) {
        if (edge[0] == index1 && edge[1] == index2 || edge[1] == index1 && edge[0] == index2) {
            edges.push_back(std::vector<float>{edge[0], edge[1], edge[2]});
        }
    }
    return edges;
}

std::vector<std::vector<float>> Graph::getEdges(int index1, int index2)
{
    std::vector<std::vector<float>> edges;

    for (auto edge : edges_) {
        if (edge[0] == index1 && edge[1] == index2 || edge[1] == index1 && edge[0] == index2) {
            edges.push_back(std::vector<float>{edge[0], edge[1], edge[2]});
        }
    }
    return edges;
}

void Graph::deleteEdge(int index1, int index2)
{
    for (int i = 0; i < edges_.size(); i++) {
        if (edges_[i][0] == index1 && edges_[i][1] == index2 || edges_[i][1] == index1 && edges_[i][0] == index2) {
            edges_.erase(edges_.begin() + i);
            break;
        }
    }
}

bool Graph::areConnected(Node* node1, Node* node2)
{
    int index1 = getIndex(node1);
    int index2 = getIndex(node2);
    if (index1 == -1 or index2 == -1) return false;
    // Using matrix
    /*if (index1 >= 0 && index2 >= 0 && matrix[index1][index2] == 1.0f) {
        return true;
    }*/
    // Using edges_
    for (auto edge : edges_) {
        if (edge[0] == index1 && edge[1] == index2 || edge[1] == index1 && edge[0] == index2) {
            return true;
        }
    }
    return false;
}

unsigned int Graph::getIndex(Node* node) {
    int index = -1;
    for (int i = 0; i < nodes_.size(); i++) {
        if (nodes_[i]->name_ == node->name_) {
            index = i;
        }
    }
    return index;
}

std::vector<std::vector<float>> Graph::getEdges(int index)
{
    std::vector<std::vector<float>> edges;
    for (int i = 0; i < edges_.size(); i++) {
        float first;
        float second;
        if (edges_[i][0] == index){
            first = edges_[i][0];
            second = edges_[i][1];
        }
        else if (edges_[i][1] == index) {
            first = edges_[i][1];
            second = edges_[i][0];
        }
        else {
            continue;
        }
        edges.push_back(std::vector<float>{first, second, edges_[i][2]});
    }
    return edges;
}

std::vector<size_t> Graph::getNeighbours(int index)
{
    std::vector<size_t> neighbours;
    for (auto edge : edges_) {
        if (edge[0] == index) {
            neighbours.push_back(edge[1]);
        }
        else if(edge[1] == index) {
            neighbours.push_back(edge[0]);
        }
    }
    return neighbours;
}
