#include "Node.h"

class Edge {
public:
    Edge(Node* a, Node* b, int v) : source(a), destination(b), value(v) {}

    ~Edge() {}

    Node* getSource() {
        return source;
    }

    Node* getDestination() {
        return destination;
    }

    int getValue() {
        return value;
    }

private:
    Node* source;
    Node* destination;
    int value;
};