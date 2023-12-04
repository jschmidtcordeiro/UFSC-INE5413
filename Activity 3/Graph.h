// Graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    Graph(int numVertices);
    void addEdge(int u, int v);
    void printGraph();

private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;
};

#endif // GRAPH_H

