#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:
    vector<vector<int>> adjMatrix;

    virtual vector<vector<int>> createGraphWithoutEdges(int V);

    virtual void showNeighbors(int vertex);
    void printGraph();

    virtual bool isAdjacent(int vertex1, int vertex2);
    virtual vector<int> neighbors(int vertex);
};

