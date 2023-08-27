#ifndef NODE_H
#define NODE_H

#include <list>
#include <string>
#include "Node.h"

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

private:
    std::string name;
    int value;
};

#endif // NODE_H