#include "HopcroftKarp.h"  // Inclui o arquivo de cabeçalho
#include <queue>           // Biblioteca para utilizar fila
#include <climits>         // Biblioteca para utilizar o valor INT_MAX

// Construtor da classe, inicializa o número de vértices do grafo
HopcroftKarp::HopcroftKarp(int numV) : numVertices(numV) {
    grafo.resize(numVertices + 1);
}

// Método para adicionar arestas no grafo (bidirecional)
void HopcroftKarp::adicionarAresta(int u, int v) {
    grafo[u].push_back(v);
    grafo[v].push_back(u);
}

// Função para realizar a busca em profundidade (DFS)
bool HopcroftKarp::dfs(int u, std::vector<int>& pairU, std::vector<int>& pairV, std::vector<int>& dist) {
    if (u != 0) {
        for (int v : grafo[u]) {
            if (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v], pairU, pairV, dist)) {
                pairU[u] = v;
                pairV[v] = u;
                return true;
            }
        }
        dist[u] = INT_MAX;
        return false;
    }
    return true;
}

// Função principal para encontrar o emparelhamento máximo no grafo
int HopcroftKarp::emparelhamentoMaximo() {
    std::vector<int> pairU(numVertices + 1, 0);  // Vetor para armazenar pares do lado U
    std::vector<int> pairV(numVertices + 1, 0);  // Vetor para armazenar pares do lado V
    std::vector<int> dist(numVertices + 1, INT_MAX);  // Vetor para armazenar distâncias

    int matching = 0;  // Inicializa o número de emparelhamentos como 0

    while (true) {
        std::queue<int> fila;  // Fila para a busca em largura
        for (int u = 1; u <= numVertices; ++u) {
            if (pairU[u] == 0) {
                dist[u] = 0;
                fila.push(u);
            } else {
                dist[u] = INT_MAX;
            }
        }

        while (!fila.empty()) {
            int u = fila.front();
            fila.pop();

            if (dist[u] < dist[0]) {
                for (int v : grafo[u]) {
                    if (dist[pairV[v]] == INT_MAX) {
                        dist[pairV[v]] = dist[u] + 1;
                        fila.push(pairV[v]);
                    }
                }
            }
        }

        bool flag = false;
        for (int u = 1; u <= numVertices; ++u) {
            if (pairU[u] == 0 && dfs(u, pairU, pairV, dist)) {
                matching++;
                flag = true;
            }
        }

        if (!flag) {
            break;
        }
    }

    return matching;  // Retorna o número de emparelhamentos
}

