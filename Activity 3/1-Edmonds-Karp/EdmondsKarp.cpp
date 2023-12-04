#include "EdmondsKarp.h"
#include <queue>
#include <iostream>

// Implementação dos métodos da classe EdmondsKarp

EdmondsKarp::EdmondsKarp(int vertices) {
    V = vertices;
    residualGraph.resize(vertices, std::vector<int>(vertices, 0));
}

void EdmondsKarp::addEdge(int u, int v, int capacity) {
    residualGraph[u][v] = capacity;
}

bool EdmondsKarp::bfs(int s, int t, std::vector<int>& parent) {
    std::vector<bool> visited(V, false);
    std::queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

int EdmondsKarp::maxFlow(int source, int sink) {
    int u, v;

    std::vector<std::vector<int>> rGraph = residualGraph;

    std::vector<int> parent(V, -1);
    int maxFlow = 0;

    while (bfs(source, sink, parent)) {
        int pathFlow = std::numeric_limits<int>::max();
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            pathFlow = std::min(pathFlow, rGraph[u][v]);
        }

        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}
