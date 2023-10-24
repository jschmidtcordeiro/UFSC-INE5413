#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

class Graph {
    int V; // Number of vertices
    list<int> *adj;

    void DFS(int v, bool visited[], vector<int> &scc);
    void fillOrder(int v, bool visited[], stack<int> &Stack);

public:
    Graph(int V);
    ~Graph() { delete adj; }
    void addEdge(int v, int w);
    Graph getTranspose();
    void printSCCs();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v - 1].push_back(w - 1);
}

void Graph::DFS(int v, bool visited[], vector<int> &scc) {
    visited[v] = true;
    scc.push_back(v + 1); // Push the vertex (add 1 for 1-based indexing)

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited, scc);
}

Graph Graph::getTranspose() {
    Graph g(V);
    for (int v = 0; v < V; v++) {
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack) {
    visited[v] = true;

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            fillOrder(*i, visited, Stack);

    Stack.push(v);
}

void Graph::printSCCs() {
    stack<int> Stack;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    vector<vector<int>> sccList;  // Store SCCs in a vector of vectors

    for (int i = 0; i < V; i++)
        if (!visited[i])
            fillOrder(i, visited, Stack);

    Graph transposedGraph = getTranspose();

    for (int i = 0; i < V; i++)
        visited[i] = false;

    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();

        if (!visited[v]) {
            vector<int> scc;  // Store vertices of the SCC
            transposedGraph.DFS(v, visited, scc);
            sccList.push_back(scc);  // Add SCC to the list
        }
    }

    for (const auto& scc : sccList) {
        for (size_t i = 0; i < scc.size(); i++) {
            cout << scc[i];
            if (i < scc.size() - 1)
                cout << ",";
        }
        cout << endl;
    }
}