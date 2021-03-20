#pragma once

#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;


class UndirectedGraph : public Graph
{
private:

public:
    UndirectedGraph(int numberOfVertexes);

    void addVertex();
    void removeVertex(int V);
    void addEdge(int u, int v);
    void removeEdge(int u, int v);
};

