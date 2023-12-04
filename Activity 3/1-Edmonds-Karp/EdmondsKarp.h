#ifndef EDMONDS_KARP_H
#define EDMONDS_KARP_H

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class EdmondsKarp {
    int V; // Número de vértices
    std::vector<std::vector<int>> graph; // Matriz de adjacência para representar o grafo

public:
    EdmondsKarp(int vertices); // Construtor da classe
    void addEdge(int u, int v, int capacity); // Adiciona uma aresta ao grafo
    bool bfs(int s, int t, std::vector<int>& parent); // Busca em largura para encontrar caminho de aumento
    int maxFlow(int source, int sink); // Encontra o fluxo máximo do grafo
};

// Construtor da classe EdmondsKarp
EdmondsKarp::EdmondsKarp(int vertices) : V(vertices) {
    // Inicializa a matriz de adjacência com capacidades de fluxo zeradas
    graph.resize(V, std::vector<int>(V, 0));
}

// Método para adicionar uma aresta ao grafo com capacidade de fluxo
void EdmondsKarp::addEdge(int u, int v, int capacity) {
    graph[u][v] = capacity; // Define a capacidade de fluxo da aresta
}

// Busca em largura para encontrar um caminho de aumento
bool EdmondsKarp::bfs(int s, int t, std::vector<int>& parent) {
    std::vector<bool> visited(V, false); // Vetor para marcar vértices visitados na BFS
    std::queue<int> q; // Fila para a BFS

    q.push(s); // Adiciona o vértice de origem à fila
    visited[s] = true; // Marca o vértice de origem como visitado
    parent[s] = -1; // Define o pai do vértice de origem como -1

    // Executa a busca em largura
    while (!q.empty()) {
        int u = q.front(); // Obtém o vértice da frente da fila
        q.pop(); // Remove o vértice da fila

        // Itera sobre os vértices adjacentes ao vértice atual
        for (int v = 0; v < V; ++v) {
            // Se o vértice não foi visitado e há capacidade de fluxo na aresta
            if (!visited[v] && graph[u][v] > 0) {
                q.push(v); // Adiciona o vértice à fila
                visited[v] = true; // Marca o vértice como visitado
                parent[v] = u; // Define o pai do vértice como o vértice atual
            }
        }
    }

    // Retorna verdadeiro se o vértice de destino foi visitado
    return visited[t];
}

// Encontra o fluxo máximo do grafo usando o algoritmo de Edmonds-Karp
 EdmondsKarp
int EdmondsKarp::maxFlow(int source, int sink) {
    
}

#endif // EDMONDS_KARP_H

