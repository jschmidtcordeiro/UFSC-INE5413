#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include "Node.h"
#include "Line.h"

/**
 * @class Graph
 * @brief Represents a Graph.
 *
 * @param V a set of nodes
 * @param E a set of lines
 * @param w an incidence function mapping every line to an unordered pair of nodes
 */
class Graph {
public:
    Graph(std::list<Node> V, std::list<Line> E, W) {}

    ~Graph() {}

    int numberOfNodes() {}
 
    int numberOfLines() {}
 
    int valueOfNode(Node n) {
        return n.getValue();
    }
 
    std::string nameOfNode(Node n) {}
 
    std::list<Node> neighbors(Node n) {}
 
    bool existLine (Line l) {}
 
    int valueOfLine(Line l) {}
 
    void readFile(std::string path_to_file) {}
 
};

#endif // GRAPH_H