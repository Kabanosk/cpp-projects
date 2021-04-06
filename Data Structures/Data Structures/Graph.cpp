#include "Graph.h"

vector<vector<int>> Graph::createGraphWithoutEdges(int V) {
    vector<int> tmpRow;
    vector<vector<int>> adj;
    for (int i = 0; i < V; i++) {
        tmpRow.push_back(0);
    }
    for (unsigned int i = 0; i < V; i++) {
        adj.push_back(tmpRow);
    }
    return adj;
}

void Graph::showNeighbors(int vertex) {
    vector<int> neighbors;
    for (unsigned int i = 0; i < adjMatrix.size(); i++) {
        if (adjMatrix[vertex][i] != 0) {
            neighbors.push_back(adjMatrix[vertex][i]);
        }
    }
    cout << "Neighbours of vertex number " << vertex << " are vertexes number: ";
    for (unsigned int i = 0; i < neighbors.size(); i++) {
        cout << neighbors[i] << " ";
    }
}
void Graph::printGraph() {
    for (unsigned int i = 0; i < adjMatrix.size(); i++) {
        cout << "[";
        for (unsigned int j = 0; j < adjMatrix[i].size(); j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "]\n";
    }
}

bool Graph::isAdjacent(int vertex1, int vertex2) {
    return adjMatrix[vertex1][vertex2] != 0;
}
vector<int> Graph::neighbors(int vertex) {
    vector<int> neighbors;
    for (unsigned int i = 0; i < adjMatrix.size(); i++) {
        if (adjMatrix[vertex][i] != 0) {
            neighbors.push_back(adjMatrix[vertex][i]);
        }
    }
    return neighbors;
}


DirectedGraph::DirectedGraph(int numberOfVertexes) {
    adjMatrix = createGraphWithoutEdges(numberOfVertexes);
}

void DirectedGraph::addVertex() {
    vector<int> tmpRow;
    for (unsigned int i = 0; i < adjMatrix.size(); i++) {
        tmpRow.push_back(0);
    }
    adjMatrix.push_back(tmpRow);
    for (unsigned int i = 0; i < adjMatrix.size(); i++) {
        adjMatrix[i].push_back(0);
    }
}
void DirectedGraph::removeVertex(int V) {
    adjMatrix.erase(adjMatrix.begin() + V);
    for (unsigned int i = 0; i < adjMatrix[0].size(); i++)
    {
        adjMatrix[i].erase(adjMatrix[i].begin() + V);
    }
}

void DirectedGraph::addEdge(int u, int v) {
    if (u == v)
        adjMatrix[u][v] = 2;
    else
        adjMatrix[u][v] = 1;
}
void DirectedGraph::removeEdge(int u, int v) {
    adjMatrix[u][v] = 0;
}


UndirectedGraph::UndirectedGraph(int numberOfVertexes) {
    adjMatrix = createGraphWithoutEdges(numberOfVertexes);
}

void UndirectedGraph::addVertex() {
    vector<int> tmpRow;
    for (int i = 0; i < adjMatrix.size(); i++) {
        tmpRow.push_back(0);
    }
    adjMatrix.push_back(tmpRow);
    for (int i = 0; i < adjMatrix.size(); i++) {
        adjMatrix[i].push_back(0);
    }
}
void UndirectedGraph::removeVertex(int V) {
    adjMatrix.erase(adjMatrix.begin() + V);
    for (unsigned int i = 0; i < adjMatrix[0].size(); i++)
    {
        adjMatrix[i].erase(adjMatrix[i].begin() + V);
    }
}

void UndirectedGraph::addEdge(int u, int v) {
    if (u == v)
        adjMatrix[u][v] = 2;
    else {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
}
void UndirectedGraph::removeEdge(int u, int v) {
    adjMatrix[v][u] = 0;
    adjMatrix[u][v] = 0;
}