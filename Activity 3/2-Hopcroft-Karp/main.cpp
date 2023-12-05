// Crie um programa que receba um arquivo de grafo bipartido, n˜ao-dirigido, n˜ao-ponderado
// e informe qual o valor do emparelhamento m´aximo e quais arestas pertencem a ele. Utilize o algoritmo de HopcroftKarp.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Graph.h"  // Assuming Graph.h contains the declaration of your Graph class

int main() {

    // Read the graph from the input file
    // std::ifstream fin("pequeno.net");
    std::ifstream fin("gr128_10.net");
    
    if (!fin) {
        cerr << "Cannot open the input file!" << endl;
        exit(1);
    }
    
    std::string line;

    // Read the number of vertices (Written on the first line of the input file)
    /// Reading vertices header
    int V;
    std::getline(fin, line);
    std::stringstream line_stream(line);
    std::string label;
    line_stream >> label >> V;
    cout << "Number of vertices: " << V << endl;

    Graph g(V); // Create the graph with the correct number of nodes
    
    /// Reading the vertices
    for (int i = 0; i < V; i++) {
        std::getline(fin, line);
    }

    // Read the number of edges 
    /// Reading edges header
    std::getline(fin, line);
    line_stream = std::stringstream(line);
    /// Reading the edges
    int v, w, weight;
    while (std::getline(fin, line)) {
        std::stringstream line_stream(line);
        line_stream >> v >> w >> weight;

        g.addEdge(v, w);    // Add the edge to the graph
    }

    g.printHKMatching();

    fin.close();

    return 0;
}