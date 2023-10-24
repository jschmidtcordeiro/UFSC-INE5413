#include "Graph.h"

#include<iostream>
#include<vector>
#include<set>
#include<utility>
#include<queue>
#include<functional>




std::pair<std::vector<Edge>, float> prim(Graph& G) {
    std::vector<bool> visited(G.getSize(), false);

    // Simplesmente uma obra de arte :)
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;

    for (auto&[u, w] : G.adj[0])
        pq.push(Edge(0, u, w));
    
    visited[0] = true;

    std::vector<Edge> mst;
    float total_weigth = 0;

    while (!pq.empty() && mst.size() != G.getSize() - 1) {
        Edge e = std::move(pq.top());
        pq.pop();

        if (visited[e.dest]) continue;

        visited[e.dest] = true;

        total_weigth += e.w;

        for (auto&[v, w] : G.adj[e.dest])
            if (!visited[v])
                pq.push(Edge(e.dest, v, w));
        
        mst.emplace_back(e);
    }

    return {mst, total_weigth};
}


int main(int argc, char *argv[]) {
    std::string path = (argc > 1)
                        ? argv[1]
                        : "input";
    
    auto graph = Graph::read_graph(path);

    auto[mst, total_weigth] = prim(graph);

    std::cout << total_weigth << '\n';

    for (int i = 0; i < mst.size(); ++i) {
        std::cout << mst[i].src+1 << '-' << mst[i].dest+1;

        if (i == mst.size() - 1)
            std::cout << '\n';
        else
            std::cout << ',';
    }

} 