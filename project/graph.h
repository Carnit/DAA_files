#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NODES 10
#define INF 99999

typedef struct
{
    int nodes;
    int adj[MAX_NODES][MAX_NODES];
} Graph;

// Function prototypes
void initGraph(Graph *g, int nodes);
void addEdge(Graph *g, int u, int v, int weight);
void updateWeights(Graph *g, int u, int v, int traffic_density, int accidents);
int dijkstra(Graph *g, int start, int end);
int aStar(Graph *g, int start, int end, int heuristic[]);

#endif
