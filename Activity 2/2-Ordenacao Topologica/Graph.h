#include <iostream>
#include <list>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Graph {
    int V; // Number of vertices
    list<int> *adj;
    unordered_map <int, string> nodes;

    void DFS(int v, bool visited[]);
    void fillOrder(int v, bool visited[], stack<int> &Stack);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void addNode(int id, string label);
    void printTopologicalOrder();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v - 1].push_back(w - 1);
}

void Graph::addNode(int id, string label) {
    nodes.insert({id, label});
}

void Graph::DFS(int v, bool visited[]) {
    visited[v] = true;

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited);
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack) {
    visited[v] = true;

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            fillOrder(*i, visited, Stack);

    Stack.push(v);
}

void Graph::printTopologicalOrder() {
    stack<int> Stack;
    bool *visited = new bool[V];
    
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            fillOrder(i, visited, Stack);
        }
    }

    while (!Stack.empty()) {
        if (Stack.size() == 1)
            cout << nodes[Stack.top() + 1]; // Print the vertex (add 1 for 1-based indexing)
        else if (Stack.size() > 1)
            cout << nodes[Stack.top() + 1] << " → "; // Print the vertex (add 1 for 1-based indexing)
        Stack.pop();
    }
    cout << endl;
}