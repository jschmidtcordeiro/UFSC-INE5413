#ifndef HOPCROFTKARP_H  // Guarda de inclusão para evitar múltiplas inclusões
#define HOPCROFTKARP_H

#include <vector>  // Biblioteca para utilização de vetores

class HopcroftKarp {
private:
    int numVertices;  // Número de vértices no grafo
    std::vector<std::vector<int>> grafo;  // Lista de adjacência do grafo

    bool dfs(int u, std::vector<int>& pairU, std::vector<int>& pairV, std::vector<int>& dist);

public:
    HopcroftKarp(int numV);  // Construtor da classe

    void adicionarAresta(int u, int v);  // Método para adicionar arestas no grafo
    int emparelhamentoMaximo();  // Método para encontrar o emparelhamento máximo no grafo
};

#endif /* HOPCROFTKARP_H */  // Fim da guarda de inclusão

