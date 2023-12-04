#include <iostream>
#include <fstream>
#include <sstream>
#include "EdmondsKarp.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <arquivo_de_entrada.txt>\n";
        return 1;
    }

    std::string filePath(argv[1]);
    std::ifstream fin(filePath);

    if (!fin.is_open()) {
        std::cerr << "Erro ao abrir o arquivo.\n";
        return 1;
    }
   std::string line;

    // Read the number of vertices (Written on the first line of the input file)
    /// Reading vertices header
    int V;
    std::getline(fin, line);
    std::stringstream line_stream(line);
    std::string label;
    line_stream >> label >> V;
    std::cout << "Number of vertices: " << V << std::endl;

    EdmondsKarp g(V); // Create the graph with the correct number of nodes
    
    /// Reading the vertices
    for (int i = 0; i < V; i++) {
        std::getline(fin, line);
        std::stringstream line_stream(line);
        int v, w;        
        line_stream >> v >> w;
    }

    // Read the number of edges 
    /// Reading edges header
    std::getline(fin, line);
    line_stream = std::stringstream(line);
    line_stream >> label;
    /// Reading the edges
    while (std::getline(fin, line)) {
        std::stringstream line_stream(line);
        int v, w, weight;
        line_stream >> v >> w >> weight;
        //  std::cout << "Linha:  "  << line << std::endl;
        g.addEdge(v, w, weight);    // Add the edge to the graph
    }

    fin.close(); // Fecha o arquivo após ler os dados

    // Calcula o fluxo máximo usando o algoritmo de Edmonds-Karp
    int maxFlow = g.maxFlow(1, 4);

    // Imprime o valor do fluxo máximo encontrado
    std::cout << "Fluxo máximo: " << maxFlow << std::endl;

    return 0;
}

