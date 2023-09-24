#include <queue>
#include "Graph.h"

class BreadthFirstSearch {
public:
    BreadthFirstSearch() {};
    
    ~BreadthFirstSearch() {};
    
    void search(Graph *graph, int startVertex) {
        Node* node = graph->getNode(startVertex);

        // Setting up all initial nodes
        for(Node* n : graph->getNodes()) {
            n->setVisited(false);
        }

        // Create a queue for BFS
        std::queue<Node*> queue;
        queue.push(node);
        node->setVisited(true);

        std::cout << "Breadth First Search: " << std::endl << "----------------" << std::endl;

        int nodes_to_this_depth = 0;
        int nodes_to_next_depth = node->getNeighbors().size();
        int current_depth = 0;
        std::cout << current_depth << " : ";

        while(queue.size() > 0) {
            Node* actualNode = queue.front();
            queue.pop();
            std::cout << actualNode->getValue() << " ";

            if(nodes_to_this_depth == 0) {
                current_depth++;
                std::cout << std::endl << current_depth << " : ";
                nodes_to_this_depth = nodes_to_next_depth;
                nodes_to_next_depth = 0;
            }

            for(Node* neighbor : actualNode->getNeighbors()) {
                if(!neighbor->isVisited()) {
                    neighbor->setVisited(true);
                    queue.push(neighbor);
                }
            }
            nodes_to_this_depth--;
        }
        std::cout << std::endl << "----------------" << std::endl;
    }

};
