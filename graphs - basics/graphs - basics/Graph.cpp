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