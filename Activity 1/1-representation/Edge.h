#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

class Edge {
public:
    Edge(Node* a, Node* b, int v) : source(a), destination(b), value(v) {}

    ~Edge() {}

    Node* getSource() {
        return source;
    }

    Node* getSource() const {
        return source;
    }

    Node* getDestination() {
        return destination;
    }

    Node* getDestination() const {
      return destination;
    }

    int getValue() {
        return value;
    }

    int getValue() const {
      return value;
    }

private:
    Node* source;
    Node* destination;
    int value;
};


#endif // EDGE_H
