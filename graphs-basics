#include <iostream>
#include <vector>

using namespace std;

void createGraphWithoutEdges(vector<vector<int>> &adj, int V) {
    vector<int> tmpRow;
    for (int i = 0; i < V; i++) {
        tmpRow.push_back(0);
    }
    for (unsigned int i = 0; i < V; i++) {
        adj.push_back(tmpRow);
    }
}
void addVertex(vector<vector<int>> &adj) {
    vector<int> tmpRow;
    for (int i = 0; i < adj.size(); i++) {
        tmpRow.push_back(0);
    }
    adj.push_back(tmpRow);
    for (int i = 0; i < adj.size(); i++) {
        adj[i].push_back(0);
    }
}

void addEdgeToDirectedGraph(vector<vector<int>> &adj, int u, int v) {
    if (u == v)
        adj[u][v] = 2;
    else
        adj[u][v] = 1;
}
void addEdgeToUndirectedGraph(vector<vector<int>> &adj, int u, int v) {
    if (u == v)
        adj[u][v] = 2;
    else {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

void removeEdgeToDirectedGraph(vector<vector<int>> &adj, int u, int v) {
    adj[u][v] = 0;
}
void removeEdgeToUndirectedGraph(vector<vector<int>> &adj, int u, int v) {
    adj[v][u] = 0;
    adj[u][v] = 0;
}

void printGraph(vector<vector<int>> adj) {
    for (unsigned int i = 0; i < adj.size(); i++) {
        cout << "[";
        for (unsigned int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << "]\n";
    }
}

int main()
{
    int V = 5;
    vector<vector<int>> adj;

    return 0;
}
