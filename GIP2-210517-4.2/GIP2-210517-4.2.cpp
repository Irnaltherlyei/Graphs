// GIP2-210517-4.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "FastNode.h"
#include "SlowNode.h"
#include "Graph.h"
#include "IncidencyMatrixWriter.h"
#include "AdjacencyMatrixWriter.h"
#include "Graphviz.h"
#include "EdgeTable.h"
#include "Djikstra.h"
#include "FloydWarshall.h"
#include "Postman.h"
#include <fstream>

int main()
{
    /*Graph graph;
    Node* node1 = new SlowNode("FOO", 1.2f, 3.4f);
    graph.addNode(node1);
    Node* node2 = new FastNode("BAR", 5.6f, 7.8f);
    graph.addNode(node2);
    std::cout << graph.toString() << std::endl;*/

    int countNodes;
    std::string name;
    char type;
    float x;
    float y;
    Node* node = NULL;

    // READ FROM CONSOLE
    /*std::cin >> countNodes;
    for (int i = 0; i < countNodes; i++) {
        if ((std::cin >> type >> name >> x >> y).good()) {
            if (type == 'L') {
                node = new SlowNode(name, x, y);
                graph.addNode(node);
            }
            else if (type == 'H') {
                node = new FastNode(name, x, y);
                graph.addNode(node);
            }
        }
    }
    std::cout << &graph << std::endl;*/

    // READ FROM FILE
    std::ifstream file;
    file.open("in.txt");

    std::string tmp;
    std::getline(file, tmp);
    int z = 0;
    z = stoi(tmp);
    Graph* graph = new Graph(z);

    if (file.is_open()) {
        for (int i = 0; i < z; i++) {
            file >> type >> name >> x >> y;
            if (type == 'L') {
                node = new SlowNode(name, x, y);
                graph->addNode(node);
            }
            else if (type == 'H') {
                node = new FastNode(name, x, y);
                graph->addNode(node);
            }
        }
        file >> tmp;
        int node1 = -1;
        int node2 = -1;
        float weight = 1.0f;
        while (file >> node1 >> node2 >> weight) {
            if (node1 >= 0 && node2 >= 0 && node1 < z && node2 < z) {
                graph->connectNodes(node1, node2, weight);
            }
        }
        file.close();
    }

    // PRINT TO STDIO
    /*std::cout << new AdjacencyMatrixWriter(graph) << std::endl;
    std::cout << new IncidencyMatrixWriter(graph) << std::endl;
    std::cout << new EdgeTable(graph) << std::endl;
    std::cout << new Graphviz(graph) << std::endl;*/

    // WRITE IN FILE
    std::ofstream in("out.txt");
    if (in.is_open()) {
        in << new Graphviz(graph);
        //in << new AdjacencyMatrixWriter(graph);
        //in << new IncidencyMatrixWriter(graph);
        //in << new EdgeTable(graph);
        //in << new Djikstra(graph, 0);                   // Returns cost matrix and parent matrix
        //in << new FloydWarshall(graph);               // Returns cost matrix and parent matrix
        in.close();
    }
    new Postman(graph);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
