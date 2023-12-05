#include "EdmondsKarp.h"
#include <queue>
#include <iostream>

// Implementação dos métodos da classe EdmondsKarp

// Construtor: inicializa o número de vértices e a matriz da rede residual
EdmondsKarp::EdmondsKarp(int vertices) {
    V = vertices;
    residualGraph.resize(vertices, std::vector<int>(vertices, 0));
}

// Adiciona uma aresta no grafo residual com capacidade
void EdmondsKarp::addEdge(int u, int v, int capacity) {
    residualGraph[u][v] = capacity;
}

// Algoritmo de busca em largura para encontrar caminhos aumentantes
bool EdmondsKarp::bfs(int s, int t, std::vector<int>& parent) {
    std::cout << "1\n";
    std::vector<bool> visited(V, false); // Marca os vértices como não visitados
    std::queue<int> q;
    q.push(s); // Adiciona o vértice fonte à fila
    visited[s] = true; // Marca o vértice fonte como visitado
    parent[s] = -1; // Inicializa o pai do vértice fonte como -1

    // Executa até a fila estar vazia
    while (!q.empty()) {
        int u = q.front();
        q.pop();
         std::vector<int> p;
        // Percorre os vértices adjacentes
        for (int v = 0; v < V; ++v) {
            // Verifica se o vértice não foi visitado e há capacidade residual na aresta
            if (!visited[v] && residualGraph[u][v] > 0) {
                q.push(v); // Adiciona o vértice à fila
                parent[v] = u; // Define o pai do vértice atual
                visited[v] = true; // Marca o vértice como visitado
               
            }
        }
    }

    return visited[t]; // Retorna true se o vértice sorvedouro foi visitado
}

// Encontra o fluxo máximo de s para t no grafo usando o algoritmo de Edmonds-Karp
int EdmondsKarp::maxFlow(int source, int sink) {
    int u, v;

    std::vector<std::vector<int>>& rGraph = residualGraph; // Cria uma cópia da rede residual

    std::vector<int> parent(V, -1); // Array para armazenar os pais dos vértices
    int maxFlow = 0; // Inicializa o fluxo máximo como 0

    // Enquanto houver um caminho aumentante
    while (bfs(source, sink, parent)) {
        int pathFlow = std::numeric_limits<int>::max(); // Inicializa o fluxo do caminho como infinito

        // Encontra a capacidade residual mínima do caminho encontrado
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            pathFlow = std::min(pathFlow, rGraph[u][v]);
        }

        // Atualiza as capacidades residuais das arestas e de seus reversos
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= pathFlow; // Atualiza a capacidade residual da aresta
            rGraph[v][u] += pathFlow; // Atualiza a capacidade residual de sua aresta reversa
        }

        maxFlow += pathFlow; // Adiciona o fluxo do caminho ao fluxo máximo
    }

    return maxFlow; // Retorna o fluxo máximo encontrado
}
