#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Initialize graph
void initGraph(Graph *g, int nodes)
{
    g->nodes = nodes;
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            g->adj[i][j] = (i == j) ? 0 : INF;
        }
    }
}

// Add an edge
void addEdge(Graph *g, int u, int v, int weight)
{
    g->adj[u][v] = weight;
    g->adj[v][u] = weight; // For undirected graph
}

// Update weights based on congestion
void updateWeights(Graph *g, int u, int v, int traffic_density, int accidents)
{
    if (accidents > 0)
    {
        g->adj[u][v] = INF; // Close the road
        g->adj[v][u] = INF;
    }
    else if (traffic_density > 70)
    {
        g->adj[u][v] *= 2; // Increase weight for congestion
        g->adj[v][u] *= 2;
    }
}

// Dijkstra's algorithm
int dijkstra(Graph *g, int start, int end)
{
    int dist[MAX_NODES], visited[MAX_NODES], prev[MAX_NODES];
    for (int i = 0; i < g->nodes; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
        prev[i] = -1;
    }

    dist[start] = 0;
    for (int i = 0; i < g->nodes; i++)
    {
        int minDist = INF, u = -1;
        for (int j = 0; j < g->nodes; j++)
        {
            if (!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1 || u == end)
            break;
        visited[u] = 1;

        for (int v = 0; v < g->nodes; v++)
        {
            if (!visited[v] && g->adj[u][v] != INF)
            {
                int alt = dist[u] + g->adj[u][v];
                if (alt < dist[v])
                {
                    dist[v] = alt;
                    prev[v] = u;
                }
            }
        }
    }
    return dist[end];
}

// A* algorithm
int aStar(Graph *g, int start, int end, int heuristic[])
{
    int dist[MAX_NODES], visited[MAX_NODES];
    for (int i = 0; i < g->nodes; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;
    while (1)
    {
        int minDist = INF, u = -1;
        for (int i = 0; i < g->nodes; i++)
        {
            if (!visited[i] && dist[i] + heuristic[i] < minDist)
            {
                minDist = dist[i] + heuristic[i];
                u = i;
            }
        }

        if (u == -1 || u == end)
            break;
        visited[u] = 1;

        for (int v = 0; v < g->nodes; v++)
        {
            if (!visited[v] && g->adj[u][v] != INF)
            {
                int alt = dist[u] + g->adj[u][v];
                if (alt < dist[v])
                {
                    dist[v] = alt;
                }
            }
        }
    }
    return dist[end];
}
