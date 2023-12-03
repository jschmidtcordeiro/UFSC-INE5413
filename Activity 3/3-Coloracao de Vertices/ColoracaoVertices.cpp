#include "ColoracaoVertices.h"  // Inclui o arquivo de cabeçalho

ColoracaoVertices::ColoracaoVertices(int numV) : numVertices(numV) {
    grafo.resize(numVertices + 1);
}

void ColoracaoVertices::adicionarAresta(int u, int v) {
    grafo[u].push_back(v);
    grafo[v].push_back(u);
}

int ColoracaoVertices::coloracaoMinima() {
    std::vector<int> cor(numVertices + 1, -1);  // Vetor para armazenar a cor de cada vértice

    int numeroCromatico = 0;  // Inicializa o número cromático como 0

    for (int u = 1; u <= numVertices; ++u) {
        std::vector<bool> disponivel(numVertices + 1, true);  // Vetor para verificar disponibilidade de cores
        for (int v : grafo[u]) {
            if (cor[v] != -1) {
                disponivel[cor[v]] = false;
            }
        }

        int corUtilizada;
        for (corUtilizada = 1; corUtilizada <= numVertices; ++corUtilizada) {
            if (disponivel[corUtilizada]) {
                break;
            }
        }

        cor[u] = corUtilizada;
        numeroCromatico = std::max(numeroCromatico, corUtilizada);  // Atualiza o número cromático
    }

    // Imprime a coloração mínima e o número cromático de cada vértice
    for (int u = 1; u <= numVertices; ++u) {
        std::cout << "Vértice " << u << ": Cor " << cor[u] << std::endl;
    }

    std::cout << "Número cromático: " << numeroCromatico << std::endl;

    return numeroCromatico;
}

