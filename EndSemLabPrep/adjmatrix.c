#include <stdio.h>
#define MAX 10

// Function to create a graph (directed or undirected)
void createGraph(int adj[MAX][MAX], int vertices, int edges, int directed) {
    int i, j, u, v;

    // Step 1: Initialize all entries of adjacency matrix to 0
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
    }

    // Step 2: Take edge input from user
    printf("Enter edges (u v) one by one:\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;          // add edge u → v

        if (!directed)
            adj[v][u] = 1;      // add reverse edge for undirected graph
    }
}

// Function to display adjacency matrix
void displayGraph(int adj[MAX][MAX], int vertices) {
    int i, j;
    printf("\nAdjacency Matrix:\n   ");
    for (i = 0; i < vertices; i++)
        printf("%2d ", i);
    printf("\n");

    for (i = 0; i < vertices; i++) {
        printf("%2d ", i);
        for (j = 0; j < vertices; j++) {
            printf("%2d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, directed;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Is the graph directed? (1 = Yes, 0 = No): ");
    scanf("%d", &directed);

    createGraph(adj, vertices, edges, directed);
    displayGraph(adj, vertices);

    return 0;
}
