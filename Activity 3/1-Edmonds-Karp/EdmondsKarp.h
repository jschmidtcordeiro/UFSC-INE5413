#ifndef EDMONDSKARP_H
#define EDMONDSKARP_H

#include <vector>
#include <limits>

class EdmondsKarp {
private:
    int V;
    std::vector<std::vector<int>> residualGraph;

    bool bfs(int s, int t, std::vector<int>& parent);

public:
    EdmondsKarp(int vertices);
    void addEdge(int u, int v, int capacity);
    int maxFlow(int source, int sink);
};

#endif // EDMONDSKARP_H
