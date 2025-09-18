#include <stdio.h>
#include <stdlib.h>
#include <limits.h >
#define MAX_VERTICES 100

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    int parent;
    int weight;
} Node;

void primsMST(int graph[][MAX_VERTICES], int numVertices) {
    Node nodes[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};
    int minIndex, minWeight;

    // Initialize nodes
    for (int i = 0; i < numVertices; i++) {
        nodes[i].parent = -1;
        nodes[i].weight = INT_MAX;
    }

    // Set the first node as visited and its weight to 0
    nodes[0].weight = 0;

    // Repeat until all vertices are visited
    for (int i = 0; i < numVertices - 1; i++) {
        minIndex = -1;
        minWeight = INT_MAX;

        // Find the unvisited node with the smallest weight
        for (int j = 0; j < numVertices; j++) {
            if (!visited[j] && nodes[j].weight < minWeight) {
                minIndex = j;
                minWeight = nodes[j].weight;
            }
        }

        // Mark the node as visited
        visited[minIndex] = 1;

        // Update the weights of unvisited neighbors
        for (int j = 0; j < numVertices; j++) {
            if (!visited[j] && graph[minIndex][j] && graph[minIndex][j] < nodes[j].weight) {
                nodes[j].weight = graph[minIndex][j];
                nodes[j].parent = minIndex;
            }
        }
    }

    // Print the MST
    printf("Minimum Spanning Tree:\n");
    for (int i = 1; i < numVertices; i++) {
        printf("%d - %d (weight: %d)\n", nodes[i].parent, i, nodes[i].weight);
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 7, 0, 5, 0},
        {7, 0, 8, 9, 0},
        {0, 8, 0, 10, 2},
        {5, 9, 10, 0, 6},
        {0, 0, 2, 6, 0}
    };
    int numVertices = 5;

    primsMST(graph, numVertices);

    return 0;
}