#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    int parent;
    int rank;
} DisjointSet;

int find(DisjointSet *sets, int x) {
    if (sets[x].parent != x) {
        sets[x].parent = find(sets, sets[x].parent);
    }
    return sets[x].parent;
}

void union_sets(DisjointSet *sets, int x, int y) {
    int rootX = find(sets, x);
    int rootY = find(sets, y);

    if (sets[rootX].rank < sets[rootY].rank) {
        sets[rootX].parent = rootY;
    } else if (sets[rootX].rank > sets[rootY].rank) {
        sets[rootY].parent = rootX;
    } else {
        sets[rootY].parent = rootX;
        sets[rootX].rank++;
    }
}

int compareEdges(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

void kruskalMST(int graph[][MAX_VERTICES], int numVertices) {
    Edge edges[MAX_VERTICES * (MAX_VERTICES - 1) / 2];
    DisjointSet sets[MAX_VERTICES];
    int numEdges = 0;

    // Create edges from the adjacency matrix
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            if (graph[i][j] != 0) {
                edges[numEdges].u = i;
                edges[numEdges].v = j;
                edges[numEdges].weight = graph[i][j];
                numEdges++;
            }
        }
    }

    // Initialize disjoint sets
    for (int i = 0; i < numVertices; i++) {
        sets[i].parent = i;
        sets[i].rank = 0;
    }

    // Sort edges by weight
    qsort(edges, numEdges, sizeof(Edge), compareEdges);

    // Build the MST
    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (find(sets, u) != find(sets, v)) {
            printf("%d - %d (weight: %d)\n", u, v, weight);
            union_sets(sets, u, v);
        }
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

    kruskalMST(graph, numVertices);

    return 0;
}