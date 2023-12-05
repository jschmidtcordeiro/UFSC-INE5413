#include <iostream>
#include <fstream>
#include <sstream>
#include "EdmondsKarp.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <arquivo-de-input>\n";
        return 1;
    }

    std::string filename(argv[1]);
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Não foi possível abrir o arquivo " << filename << std::endl;
        return 1;
    }
        
    std::string line;
    

    // Lê a primeira linha para identificar a quantidade de vértices
    
    int V;
    std::getline(file, line);
    std::stringstream line_stream(line);
    std::string label;
    line_stream >> label >> V;
    std::cout << "Number of vertices: " << V << std::endl;
    //Necessita ler todos os vertices
    while(getline(file, line) ){
        if(line == "*arcs"){
            break;
        }
        
    }


    // Inicializa o objeto EdmondsKarp com o número de vértices
    EdmondsKarp ek(V);

    // Lê as arestas do arquivo e adiciona ao grafo
    int u = 0;
    int v = 0;
    int capacity = 0;
    while (getline(file, line)) {
        std::stringstream ss(line);
        // std::cout <<  "line" << std::endl;
        std::cout <<  line << std::endl;
        ss >> u >> v >> capacity;
        ek.addEdge(u - 1, v - 1, capacity); // Decrementa 1 dos vértices para começar de 0
    }

    int source = 0; // Define o vértice fonte como 0
    int sink = V - 1; // Define o vértice sorvedouro como V - 1

    // Calcula o fluxo máximo usando o algoritmo de Edmonds-Karp
    int maxFlow = ek.maxFlow(source, sink);
    std::cout <<  line << std::endl;
    std::cout << "O valor do fluxo máximo é: " << maxFlow << std::endl;

    file.close(); // Fecha o arquivo

    return 0;
}
