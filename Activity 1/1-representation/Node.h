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
    Node(const std::string& name, int value) {
        this->name = name;
        this->value = value;
    }

    ~Node() {}

    // Getter for name
    const std::string& getName() const {
        return name;
    }

    // Getter for value
    int getValue() const {
        return value;
    }

    void addLine(Node& node, int weight) {
        // this->edges[node.getValue()] = std::make_pair(node, weight);
        this->edges.insert({node.getValue(), std::make_pair(node, weight)});
    }

    const std::unordered_map<int, std::pair<Node, int>>& getEdges() const {
        return edges;
    }

    bool hasEdge(int node_value) const {
        return edges.count(node_value) != 0;
    }

    const std::pair<Node, int>& getEdge(int node_value) const {
        return edges.at(node_value);
    }

    /**
     * @brief Get the neighbors of a node.
     *
     * @return a vector of nodes
     */
    std::vector<Node> getNeighbors() {
        std::vector<Node> neighbors;

        for (auto&[_, edge] : edges) {
            neighbors.push_back(edge.first);
        }

        return neighbors;
    }

private:
    std::string name;
    int value;
    std::unordered_map<int, std::pair<Node, int>> edges;
};

#endif // NODE_H