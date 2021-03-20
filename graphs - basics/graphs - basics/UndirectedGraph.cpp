#include "UndirectedGraph.h"
#include "Graph.h"

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