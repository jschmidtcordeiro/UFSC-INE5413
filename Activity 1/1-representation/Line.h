#ifndef LINE_H
#define LINE_H

#include <list>
#include "Node.h"

/**
 * @class Line
 * @brief Represents a Line.
 *
 * @param start The starting node.
 * @param end The ending node.
 * @param direction If true, the line has direction; if false, it is bidirectional.
 * @param value The value associated with the line.
 */
class Line {
public:
    /**
     * @brief Constructor for the Line class.
     *
     * @param start The starting node.
     * @param end The ending node.
     * @param direction If true, the line has direction; if false, it is bidirectional.
     * @param value The value associated with the line.
     */
    Line(Node start, Node end, bool direction, int value)
        : start(start), end(end), direction(direction), value(value) {
    }

    ~Line() {}

    /**
     * @brief Getter for the starting node.
     *
     * @return The starting node.
     */
    const Node& getStart() const {
        return start;
    }

    /**
     * @brief Getter for the ending node.
     *
     * @return The ending node.
     */
    const Node& getEnd() const {
        return end;
    }

    /**
     * @brief Check if the line has direction.
     *
     * @return True if the line has direction; false if it is bidirectional.
     */
    bool hasDirection() const {
        return direction;
    }

    /**
     * @brief Getter for the value associated with the line.
     *
     * @return The value associated with the line.
     */
    int getValue() const {
        return value;
    }

private:
    Node start;
    Node end;
    bool direction;
    int value;
};

#endif // LINE_H