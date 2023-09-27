#ifndef NODE_H
#define NODE_H


#include <vector>
#include <unordered_map>
#include <functional>
#include <string>
#include <utility>


class Edge;

/**
 * @class Node
 * @brief Represents a Node.
 *
 * @param value the value that a Node have
 */
class Node {
public:
    /**
     * @brief Constructor for the Node class.
     *
     * @param name The name of the node.
     * @param value The value associated with the node.
     */
    Node(std::string name, int value) {
        this->name = name;
        this->value = value;
    }

    ~Node() {}

    // Getter for name
    std::string getName() const {
        return name;
    }

    // Getter for value
    int getValue() const {
        return value;
    }

    void addNeighbor(Node* n) {
        neighbors.push_back(n);
    }

    void addEdge(Edge* e) {
        edges.push_back(e);
    }


    void setVisited(bool visited) {
        this->visited = visited;
    }

    bool isVisited() {
        return visited;
    }

    void setDepth(int depth) {
        this->depth = depth;
    }

    int getDepth() {
        return depth;
    }

    /**
     * @brief Get the neighbors of a node.
     *
     * @return a vector of nodes
     */
    std::vector<Node*> getNeighbors() {
        return neighbors;
    }

    std::vector<Edge*> getEdges() {
        return edges;
    }

    bool hasEdge(int node_value) const {
        for (Node* n : neighbors) {
            if (n->getValue() == node_value) {
                return true;
            }
        }
        return false;
    }

private:
    std::string name;
    int value;
    bool visited;
    int depth;
    std::vector<Node*> neighbors;
    std::vector<Edge*> edges;
};

#endif // NODE_H