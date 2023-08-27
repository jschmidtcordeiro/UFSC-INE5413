#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include "Node.h"
#include "Line.h"

/**
 * @class Graph
 * @brief Represents a Graph.
 *
 */
class Graph {
public:
    Graph() :lines{0} {}

    ~Graph() {}
    
    int numberOfNodes() const {
        return nodesVector.size();
    }
 
    int numberOfLines() const {
        return lines;
    }

    int nodeDegree(Node& node) const {
        return node.getEdges().size();
    }
 
    /**
     * @brief Get the neighbors of a node.
     *
     * @param n a node
     * 
     * @return a vector of nodes
     */
    std::vector<Node> getNeighbors(Node n) {
        return n.getNeighbors();
    }
    
    int valueOfNode(Node n) {
        return n.getValue();
    }
 
    std::string nameOfNode(Node n) {
        return n.getName();
    }
 
 
    bool existLine (const Node& u, const Node& v) {
        return u.hasEdge(v.getValue());
    }
 
    int valueOfLine(const Node& u, const Node& v) {
        return u.getEdge(v.getValue()).second;
    }
 
    void readFile(std::string path_to_file) {
        std::ifstream inputFile(path_to_file); // Open the file for reading
        
        if (!inputFile.is_open()) {
            std::cerr << "Could not open the file." << std::endl;
            return;
        }        
        std::string line;

        bool readingNodes = false;
        bool readingEdges = false;

        
        while (std::getline(inputFile, line)) {
            if (line.find("*vertices") != std::string::npos ) {
                readingNodes = true;
                continue;
            }
            if (line == "*edges") {
                readingNodes = false;
                readingEdges = true;
                continue;
            }

            std::stringstream line_stream(line);
            if (readingNodes) {
                int nodeIndex;
                std::string label;

                line_stream >> nodeIndex >> label;
                Node node(label, nodeIndex);
                this->nodesVector.push_back(node);
            } else if (readingEdges) {
                int a, b, weight;
                line_stream >> a >> b >> weight;
                nodesVector[a - 1].addLine(nodesVector[b - 1], weight);
                if (a != b) {   // If the node has a line to himselft
                    nodesVector[b - 1].addLine(nodesVector[a - 1], weight);
                }
            }

        }
        
        inputFile.close(); // Close the file when done

    }
 
private:
    std::vector<Node> nodesVector;
    int lines;

};

#endif // GRAPH_H