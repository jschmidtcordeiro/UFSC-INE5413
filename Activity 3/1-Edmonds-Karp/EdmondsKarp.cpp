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
int EdmondsKarp::maxFlow(int source, int sink) {
    int u, v;
    std::vector<int> parent(V, -1); // Vetor para armazenar o caminho de aumento
    int max_flow = 0; // Inicializa o fluxo máximo como zero

    // Enquanto existir um caminho de aumento, atualiza o fluxo máximo
    while (bfs(source, sink, parent)) {
        int path_flow = INT_MAX; // Inicializa o fluxo do caminho como infinito

        // Encontra a capacidade mínima ao longo do caminho
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            path_flow = std::min(path_flow, graph[u][v]);
        }

        // Atualiza as capacidades residuais das arestas e capacidades de fluxo
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            graph[u][v] -= path_flow;
            graph[v][u] += path_flow;
        }

        // Adiciona o fluxo do caminho ao fluxo máximo
        max_flow += path_flow;
    }

    // Retorna o fluxo máximo do grafo
    return max_flow;
}

