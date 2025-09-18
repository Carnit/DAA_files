#include <stdio.h>
#include "graph.h"

int main()
{
    Graph g;
    initGraph(&g, 10); // Initialize graph with 10 nodes

    // Add edges with initial weights
    addEdge(&g, 0, 1, 4);
    addEdge(&g, 0, 2, 8);
    addEdge(&g, 1, 2, 2);
    addEdge(&g, 1, 3, 6);
    addEdge(&g, 2, 4, 7);
    addEdge(&g, 3, 4, 5);
    addEdge(&g, 3, 5, 10);
    addEdge(&g, 4, 6, 6);
    addEdge(&g, 5, 7, 15);
    addEdge(&g, 6, 7, 4);
    addEdge(&g, 7, 8, 8);
    addEdge(&g, 8, 9, 10);
    addEdge(&g, 7, 9, 6);

    // Simulate congestion
    printf("Updating weights based on congestion...\n");
    updateWeights(&g, 0, 2, 85, 0); // High traffic density
    updateWeights(&g, 3, 4, 0, 1);  // Road closure due to accident
    updateWeights(&g, 6, 7, 65, 0); // Medium traffic density

    // Display shortest paths from node 0 to node 9
    int heuristic[] = {20, 18, 15, 13, 10, 8, 6, 4, 2, 0}; // Example heuristic for A*
    printf("Shortest path (Dijkstra's) from 0 to 9: %d\n", dijkstra(&g, 0, 9));
    printf("Shortest path (A*) from 0 to 9: %d\n", aStar(&g, 0, 9, heuristic));

    return 0;
}
