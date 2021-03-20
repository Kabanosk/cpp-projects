#include <iostream>
#include <vector>
#include "UndirectedGraph.h"

using namespace std;

int main()
{
    int V = 5;

    UndirectedGraph uGraph = UndirectedGraph(V);
    uGraph.addEdge(1, 3);
    uGraph.addEdge(3, 3);
    uGraph.addEdge(2, 3);
    uGraph.addEdge(4, 3);
    uGraph.printGraph();
    uGraph.removeVertex(4);
    uGraph.printGraph();
    return 0;
}