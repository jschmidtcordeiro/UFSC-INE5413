#ifndef NODE_H
#define NODE_H


#include <vector>
#include <unordered_map>
#include <functional>
#include <string>
#include <utility>
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

    /**
     * @brief Get the neighbors of a node.
     *
     * @return a vector of nodes
     */
    std::vector<Node*> getNeighbors() {
        return neighbors;
    }

    // const std::unordered_map<int, std::pair<Node, int>>& getEdges() const {
    //     return edges;
    // }

    // bool hasEdge(int node_value) const {
    //     return edges.count(node_value) != 0;
    // }

    // /**
    //  * @brief Get an edge
    //  *
    //  * @param node_value The value of an edge
    //  * 
    //  * @return A reference to a pair that inform the node and the 
    //  * value of the line that connects to these two nodes
    //  */
    // const std::pair<Node, int>& getEdge(int node_value) const {
    //     return edges.at(node_value);
    // }



private:
    std::string name;
    int value;
    std::vector<Node*> neighbors;
};

#endif // NODE_H