#pragma once

#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;

class DirectedGraph : public Graph
{
public:
    DirectedGraph(int numberOfVertexes);

    void addVertex();
    void removeVertex(int V);
    void addEdge(int u, int v);
    void removeEdge(int u, int v);
};

