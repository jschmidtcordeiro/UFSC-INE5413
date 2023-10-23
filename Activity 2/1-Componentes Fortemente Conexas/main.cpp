#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Graph.h"  // Assuming Graph.h contains the declaration of your Graph class

int main() {
    std::ifstream inputFile;
    inputFile.open("input");

    if (!inputFile.is_open()) {
        std::cerr << "Could not open the file." << std::endl;
        return 1;  // Return an error code
    }        

    bool readingNodes = true;
    bool readingEdges = false;
    
    int nodeNumber;


    std::string line;
    std::getline(inputFile, line);
    std::stringstream line_stream(line);
    std::string label;  // You need to add this variable
    line_stream >> label >> nodeNumber;  // Corrected line

    Graph g(nodeNumber);  // Create the graph with the correct number of nodes

    while (std::getline(inputFile, line)) {
        std::stringstream line_stream(line);

        if (line == "*edges") {
            readingNodes = false;
            readingEdges = true;
            continue;
        }

        if (readingNodes) {
            int nodeIndex;
            std::string label;
            line_stream >> nodeIndex >> label;
        } else if (readingEdges) {
            int a, b, weight;
            line_stream >> a >> b >> weight;
            // std::cout << a << " " << b << " " << weight << std::endl;
            g.addEdge(a, b);
        }
    }

    g.printSCCs();

    inputFile.close();

    return 0;
}
