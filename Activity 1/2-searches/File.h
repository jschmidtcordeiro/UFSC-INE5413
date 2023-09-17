#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class File {
public:
    File(std::string p) : path_to_file(p) {}

    ~File() {}

    std::vector<std::pair<std::string, int>> getNodesVector() {
        return nodes_vector;
    }

    std::vector<std::vector<int>> getEdgesVector() {
        return edges_vector;
    }

    void readFile() {
        std::ifstream inputFile(path_to_file); // Open the file for reading
        
        if (!inputFile.is_open()) {
            std::cerr << "Could not open the file." << std::endl;
            return;
        }        
        std::string line;

        bool readingNodes = false;
        bool readingEdges = false;
        
        while (std::getline(inputFile, line)) {
            if (line.find("*vertices") != std::string::npos ) {
                readingNodes = true;
                continue;
            }
            if (line == "*edges") {
                readingNodes = false;
                readingEdges = true;
                continue;
            }

            std::stringstream line_stream(line);
            std::cout << line << std::endl;
            if (readingNodes) {
                int nodeIndex;
                std::string label;

                line_stream >> nodeIndex >> label;
                nodes_vector.push_back({label, nodeIndex});
                
            } else if (readingEdges) {
                int a, b, weight;
                line_stream >> a >> b >> weight;
                
                edges_vector.push_back({a, b, weight});
            }
        }

        inputFile.close();
    }


private:
    std::vector<std::pair<std::string, int>> nodes_vector;
    std::vector<std::vector<int>> edges_vector;
    std::string path_to_file;
};