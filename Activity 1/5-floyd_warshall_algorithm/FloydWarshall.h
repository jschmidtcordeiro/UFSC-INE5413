#include <climits>
#include "Graph.h"

typedef std::vector<std::vector<int>> Matrix;


class FloydWarshall {
public:
    FloydWarshall() {
    }

    ~FloydWarshall() {}

    void search(Graph* g) {
        adjacency_matrixes.push_back(WMethod(g));

        for(int k = 1; k <= g->numberOfNodes(); k++) {
            adjacency_matrixes.push_back(createMatrix(g->numberOfNodes(), g->numberOfNodes()));

            for(int u = 0; u < g->numberOfNodes(); u++) {
                for(int v = 0; v < g->numberOfNodes(); v++) {
                    int a = adjacency_matrixes[k - 1][u][v];
                    int b = adjacency_matrixes[k - 1][u][k - 1] + adjacency_matrixes[k - 1][k - 1][v];
                    if(b < 0) {
                        b = INT_MAX;
                    }
                    adjacency_matrixes[k][u][v] = std::min(a, b);
                }
            }
        }

        for(int u = 0; u < g->numberOfNodes(); u++) {
            std::cout << u + 1 << ":";
            for(int v = 0; v < g->numberOfNodes(); v++) {
                std::cout << adjacency_matrixes[g->numberOfNodes()][u][v] << ",";
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<Matrix> adjacency_matrixes;

    Matrix WMethod (Graph* g) {
        Matrix m = createMatrix(g->numberOfNodes(), g->numberOfNodes());
        for(int i = 0; i < g->numberOfNodes(); i++) {
            for(int j = 0; j < g->numberOfNodes(); j++) {
                if (i == j) {
                    m[i][j] = 0;
                } else if (g->hasEdge(g->getNode(i+1),g->getNode(j+1))) {
                    m[i][j] = g->getValueOfEdge(g->getNode(i+1),g->getNode(j+1));
                } else {
                    m[i][j] = INT_MAX;
                }
            }
        }
        return m;
    };

    // Function to create a new matrix
    Matrix createMatrix(int rows, int cols) {
        // Initialize the matrix with zeros
        return Matrix(rows, std::vector<int>(cols, 0));
    }
};


