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

    std::vector<Edge*> getNeighbors(Node* n) {
        return n->getNeighbors();
    }

    const std::vector<Node*>& getNodes() const {
      return nodes_vector;
    }
    std::vector<Node*>& getNodes() {
      return nodes_vector;
    }

    // --------------------------//
    // ---------- Edge ----------//
    // --------------------------//

    void addEdge(int i_node_a, int i_node_b, int value) {
        Node* a = getNode(i_node_a);
        Node* b = getNode(i_node_b);
        
        // O grafo é não-dirigido, então adicionamos duas 
        // arestas
        Edge* edge_a_b = new Edge(a, b, value);
        edges_vector.push_back(edge_a_b);
        Edge* edge_b_a = new Edge(b, a, value);
        edges_vector.push_back(edge_b_a);
    
        a->addNeighbor(edge_a_b);
        b->addNeighbor(edge_b_a);
    }

    int numberOfEdges() const {
        return edges_vector.size();
    }
 
    bool hasEdge (Node* u, Node* v) {
      for (auto edge : u->getNeighbors()) {
        if (edge->getDestination()->getName() == v->getName()) {
          return true;
        }
      }

      // Grafo é não-dirigido, logo (u,v) == (v,u)
      for (auto edge : v->getNeighbors()) {
        if (edge->getDestination()->getName() == u->getName()) {
          return true;
        }
      }

      return false;
    }

    int valueOfEdge(Node* u, Node* v) {
      for (auto edge : u->getNeighbors()) {
        if (edge->getDestination()->getName() == v->getName()) {
          return edge->getValue();
        }
      }

      return 2e9; //edge não existe, então retornamos infinito
    }

private:
    std::vector<Node*> nodes_vector;
    std::vector<Edge*> edges_vector;
};

#endif // GRAPH_H
