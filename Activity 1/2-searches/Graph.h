#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include "Node.h"
#include "Edge.h"

/**
 * @class Graph
 * @brief Represents a Graph.
 *
 */
class Graph {
public:
    Graph() {}

    ~Graph() {
        for(int i = 0; i < nodes_vector.size(); i++) {
            delete nodes_vector[i];
        }
        for(int i = 0; i < edges_vector.size(); i++) {
            delete edges_vector[i];
        }
    }
    
    void addNode(std::string label, int node_index) {
        Node* new_node = new Node(label, node_index);
        nodes_vector.push_back(new_node);
 
    }
    
    int numberOfNodes() const {
        return nodes_vector.size();
    }

    int valueOfNode(Node n) {
        return n.getValue();
    }
 
    std::string nameOfNode(Node n) {
        return n.getName();
    }

    Node* getNode(int i) {
        return nodes_vector[i - 1];
    }

    std::vector<Node*> getNeighbors(Node* n) {
        return n->getNeighbors();
    }

    std::vector<Node*> getNodes() {
        return nodes_vector;
    }

    // --------------------------//
    // ---------- Edge ----------//
    // --------------------------//

    void addEdge(int i_node_a, int i_node_b, int value) {
        Node* a = getNode(i_node_a);
        Node* b = getNode(i_node_b);
        
        Edge* new_edge = new Edge(a, b, value);
        edges_vector.push_back(new_edge);
    
        a->addNeighbor(b);
        b->addNeighbor(a);
    }

    int numberOfEdges() const {
        return edges_vector.size();
    }
 
    bool hasEdge (Node* u, Node* v) {
        if(u->hasEdge(v->getValue()) || v->hasEdge(u->getValue())) {
            return true;
        }
        return false;
    }

    int getValueOfEdge(Node* u, Node* v) {
        for(Edge* e : edges_vector) {
            if((e->getSource() == u && e->getDestination() == v) || 
               (e->getSource() == v && e->getDestination() == u)) {
                return e->getValue();
            }
        }
        return -1;
    }

private:
    std::vector<Node*> nodes_vector;
    std::vector<Edge*> edges_vector;
};

#endif // GRAPH_H