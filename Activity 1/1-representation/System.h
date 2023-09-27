#include <iostream>
#include "File.h"
#include "Graph.h"

class System {
public:
    System(std::string p) {
        path_to_file = p;
        graph = new Graph;
    }

    ~System() {
        delete graph;
    }

    void run() {
        File f(path_to_file);
        f.readFile();

        for(std::pair<std::string, int> node : f.getNodesVector()) {
            graph->addNode(node.first, node.second);
            // std::cout << "First:" << node.first << " Second:" << node.second << std::endl;
        }

        for(std::vector<int> edge : f.getEdgesVector()) {
            graph->addEdge(edge[0], edge[1], edge[2]);
            // std::cout << "First:" << edge[0] << " Second:" << edge[1] << std::endl;
        }
    }

    Graph* getGraph() {
        return graph;
    }

    void search() {}

private:
    Graph* graph;
    std::string path_to_file;
};