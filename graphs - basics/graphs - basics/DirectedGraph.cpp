#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(int numberOfVertexes) {
    adjMatrix = createGraphWithoutEdges(numberOfVertexes);
}

void DirectedGraph::addVertex() {
    vector<int> tmpRow;
    for (int i = 0; i < adjMatrix.size(); i++) {
        tmpRow.push_back(0);
    }
    adjMatrix.push_back(tmpRow);
    for (int i = 0; i < adjMatrix.size(); i++) {
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