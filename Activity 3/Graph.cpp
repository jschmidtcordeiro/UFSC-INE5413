// Graph.cpp
#include "Graph.h"
#include <iostream>

Graph::Graph(int numVertices) : numVertices(numVertices) {
    adjacencyList.resize(numVertices);
}

void Graph::addEdge(int u, int v) {
    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u);
}

void Graph::printGraph() {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Adjacency list of vertex " << i << ":\n head";
        for (int node : adjacencyList[i])
            std::cout << " -> " << node;
        std::cout << std::endl;
    }
}

