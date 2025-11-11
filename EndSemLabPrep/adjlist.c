#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct node {
    int vertex;
    struct node* next;
} Node;

Node* graph[MAX_VERTICES];
int n = 0;

// Create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Add an undirected edge
void addEdge(int src, int dest) {
    // Add dest to src's list
    Node* newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;

    // Add src to dest's list
    newNode = createNode(src);
    newNode->next = graph[dest];
    graph[dest] = newNode;
}

// Display adjacency list
void displayGraph() {
    printf("\nAdjacency List Representation:\n");
    for (int i = 0; i < n; i++) {
        Node* temp = graph[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize graph
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }

    int edges;
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    displayGraph();
    return 0;
}
