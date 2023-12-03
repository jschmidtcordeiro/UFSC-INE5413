#include "EdmondsKarp.h"  // Inclui o arquivo de cabeçalho
#include <queue>          // Biblioteca para utilizar fila
#include <climits>        // Biblioteca para utilizar o valor INT_MAX

// Construtor da classe, inicializa o número de vértices do grafo
EdmondsKarp::EdmondsKarp(int numV) : numVertices(numV) {}

// Método privado para realizar a busca em largura (BFS)
bool EdmondsKarp::bfs(std::vector<std::vector<int>>& residualGraph, int origem, int destino, std::vector<int>& parent) {
    std::vector<bool> visitado(numVertices, false);  // Vetor de booleanos para controlar se um vértice foi visitado
    std::queue<int> fila;                            // Fila para armazenar os vértices a serem visitados
    fila.push(origem);                               // Adiciona o vértice de origem à fila
    visitado[origem] = true;                         // Marca o vértice de origem como visitado
    parent[origem] = -1;                             // O vértice de origem não possui um pai

    // Enquanto a fila não estiver vazia, continua a busca
    while (!fila.empty()) {
        int u = fila.front();  // Obtém o vértice da frente da fila
        fila.pop();             // Remove o vértice da frente da fila

        // Percorre os vértices adjacentes ao vértice atual
        for (int v = 0; v < numVertices; ++v) {
            // Verifica se o vértice ainda não foi visitado e se há capacidade residual na aresta
            if (!visitado[v] && residualGraph[u][v] > 0) {
                fila.push(v);       // Adiciona o vértice à fila
                parent[v] = u;      // Define o vértice atual como pai do vértice v
                visitado[v] = true; // Marca o vértice como visitado
            }
        }
    }

    return visitado[destino];  // Retorna se o destino foi alcançado
}

// Método privado para encontrar o caminho mínimo e calcular o fluxo máximo
int EdmondsKarp::minimoCaminho(std::vector<std::vector<int>>& graph, int origem, int destino) {
    std::vector<int> parent(numVertices, -1);      // Vetor para armazenar os pais dos vértices no caminho
    std::vector<std::vector<int>> residualGraph = graph;  // Grafo residual a ser modificado

    int fluxoMaximo = 0;  // Inicializa o fluxo máximo como 0

    // Enquanto houver caminho aumentante
    while (bfs(residualGraph, origem, destino, parent)) {
        int fluxoCaminho = INT_MAX;  // Inicializa o fluxo do caminho como o maior inteiro possível

        // Encontra o fluxo mínimo ao longo do caminho encontrado pela BFS
        for (int v = destino; v != origem; v = parent[v]) {
            int u = parent[v];
            fluxoCaminho = std::min(fluxoCaminho, residualGraph[u][v]);
        }

        // Atualiza as capacidades residuais das arestas ao longo do caminho
        for (int v = destino; v != origem; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= fluxoCaminho;
            residualGraph[v][u] += fluxoCaminho;
        }

        fluxoMaximo += fluxoCaminho;  // Adiciona o fluxo do caminho ao fluxo máximo
    }

    return fluxoMaximo;  // Retorna o fluxo máximo encontrado
}

// Método público para calcular o fluxo máximo do grafo
int EdmondsKarp::calcularFluxoMaximo(std::vector<std::vector<int>>& graph, int origem, int destino) {
    return minimoCaminho(graph, origem, destino);  // Chama o método privado para calcular o fluxo máximo
}

