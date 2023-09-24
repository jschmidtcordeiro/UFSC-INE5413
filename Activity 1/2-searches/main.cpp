#include "System.h"

int main() {
    System sys("input");
    sys.run();
    Graph* graph = sys.getGraph();

    Node* a = graph->getNode(1);
    Node* b = graph->getNode(2);

    // std::cout << "Has edge a to b:" << graph->hasEdge(a, b) << std::endl;

    sys.search(8);
}