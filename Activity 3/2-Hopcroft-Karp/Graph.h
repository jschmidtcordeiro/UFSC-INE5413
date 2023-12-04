#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>

using namespace std;

class Graph {
    int V; // Number of vertices
    std::map<int, vector<int>> adj;

    bool DFS(int x, int matchR[], int dist[]);
    void fillOrder(int v, bool visited[], stack<int> &Stack);

public:
    Graph(int V);
    void addEdge(int v, int w);
    Graph getTranspose();
    void printHKMatching();
    bool BFS(int matchR[], int dist[]);
    void setV(int V) { this->V = V; }
};

Graph::Graph(int V) {
    this->V = V;
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

bool Graph::DFS(int x, int matchR[], int dist[]) {
    if (x != 0) {
        for (const auto& y : adj[x]) {
            if (dist[matchR[y]] == dist[x] + 1) {
                if (DFS(matchR[y], matchR, dist)) {
                    matchR[y] = x;
                    matchR[x] = y;
                    return true;
                }
            }
        }
        dist[x] = INT_MAX;

        return false;
    }

    return true;
}

bool Graph::BFS(int mate_v[], int dist[]) {
    queue<int> q;
    for (int x = 1; x <= V/2; x++) {
        
        if (mate_v[x] == 0) {
            dist[x] = 0;
            q.push(x);
        }
        else dist[x] = INT_MAX;
    }
    dist[0] = INT_MAX;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (dist[x] < dist[0]) {
            for (const auto& y : adj[x]) {
                if (dist[mate_v[y]] == INT_MAX) {
                    dist[mate_v[y]] = dist[x] + 1;
                    q.push(mate_v[y]);
                }
            }
        }
    }

    return (dist[0] != INT_MAX);
}


void Graph::printHKMatching() {
    // Find strongly connected components
    int *dist = new int[V+1];  
    for (int i = 0; i <= V; i++)
        dist[i] = INT_MAX;  

    int *mate_v = new int[V+1];  // Array to store the matching
    for (int i = 0; i <= V; i++)
        mate_v[i] = 0;  // Initialize all vertices as not matched
    int m = 0;  // Number of edges in the matching

    while(BFS(mate_v, dist)) {
        for (int x = 1; x <= V/2; x++) {
            if (mate_v[x] == 0) {
                if (DFS(x, mate_v, dist)) {
                    m++;
                }
            }
        }
    }

    // Print the Hopcroft-Karp matching
    cout << "\nHopcroft-Karp matching:\n";
    for (int i = 1; i <= V/2; i++) {
        if (mate_v[i] != 0) {
            cout << i << " -> " << mate_v[i] << endl;
        }
    }

    cout << endl;    
}






