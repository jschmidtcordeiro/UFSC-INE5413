#ifndef COLORACAOVERTICES_H  // Guarda de inclusão para evitar múltiplas inclusões
#define COLORACAOVERTICES_H

#include <vector>  // Biblioteca para utilização de vetores

class ColoracaoVertices {
private:
    int numVertices;  // Número de vértices no grafo
    std::vector<std::vector<int>> grafo;  // Lista de adjacência do grafo

public:
    ColoracaoVertices(int numV);  // Construtor da classe

    void adicionarAresta(int u, int v);  // Método para adicionar arestas no grafo
    int coloracaoMinima();  // Método para calcular a coloração mínima e número cromático
};

#endif /* COLORACAOVERTICES_H */  // Fim da guarda de inclusão

