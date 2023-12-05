#ifndef EDMONDSKARP_H
#define EDMONDSKARP_H

#include <vector>
#include <limits>

class EdmondsKarp {
private:
    int V; // Número de vértices no grafo
    std::vector<std::vector<int>> residualGraph; // Representação da rede residual

    // Função auxiliar para busca em largura
    bool bfs(int s, int t, std::vector<int>& parent);

public:
    EdmondsKarp(int vertices); // Construtor da classe
    void addEdge(int u, int v, int capacity); // Adiciona uma aresta no grafo
    int maxFlow(int source, int sink); // Encontra o fluxo máximo no grafo
};

#endif // EDMONDSKARP_H
