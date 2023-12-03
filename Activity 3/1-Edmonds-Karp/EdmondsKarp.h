#ifndef EDMONDSKARP_H  // Guarda de inclusão para evitar múltiplas inclusões
#define EDMONDSKARP_H

#include <vector>  // Biblioteca para utilização de vetores

class EdmondsKarp {
private:
    int numVertices;  // Número de vértices no grafo

    // Método privado para busca em largura (BFS)
    bool bfs(std::vector<std::vector<int>>& residualGraph, int origem, int destino, std::vector<int>& parent);

    // Método privado para encontrar o caminho mínimo
    int minimoCaminho(std::vector<std::vector<int>>& graph, int origem, int destino);

public:
    // Construtor da classe
    EdmondsKarp(int numV);

    // Método público para calcular o fluxo máximo
    int calcularFluxoMaximo(std::vector<std::vector<int>>& graph, int origem, int destino);
};

#endif /* EDMONDSKARP_H */  // Fim da guarda de inclusão

