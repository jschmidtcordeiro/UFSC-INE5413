#include <stdexcept>
#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>

class Graph {
public:
    std::vector<std::vector<int>> adj; // 1. vértice. 2. Peso
    std::vector<std::string> id;
    Graph(int N);
    void addEdge(int u, int v);
    void addId(int v, const std::string& id);
    int getSize() const {
        return adj.size();
    }
    static Graph read_graph(const std::string& path);

};

Graph::Graph(int N) {
    adj.resize(N);
    id.resize(N);
}

void Graph::addEdge(int u, int v) {
    this->adj[u-1].push_back({v-1});
    this->adj[v-1].push_back({u-1});
}

void Graph::addId(int v, const std::string& id) {
    this->id[v-1] = id;
}


Graph Graph::read_graph(const std::string& path) {
    std::ifstream file(path);

    if (!file.good()) {
        throw std::runtime_error("Não foi possível abrir o arquivo " + path + "\n");
    }
    
    std::string throwaway;
    file >> throwaway; // ignora *vertivces

    int num_vertices;
    file >> num_vertices;

    Graph graph(num_vertices);

    file.ignore(1024, '\n');
    for (int i = 0; i < num_vertices; ++i) {
        int num;
        std::string id;
        
        std::string line;
        
        std::getline(file, line);
        std::stringstream ss(line);

        ss >> num >> id;
        graph.addId(num, id);
    }

    file >> throwaway; // ignora *edges

    int a, b;
    int w;
    while (file >> a >> b >> w) 
        graph.addEdge(a, b);
    
    return graph;
}
