#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int mat[MAX][MAX], n, directed;

void init() {
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        mat[i][j]=0;
}

void addEdge() {
    int u,v;
    printf("Enter edge (u v): ");
    scanf("%d%d",&u,&v);
    if(u>=n || v>=n || u<0 || v<0) {
        printf("Invalid vertices\n");
        return;
    }
    mat[u][v]=1;
    if(!directed) mat[v][u]=1;
}

void printMat() {
    printf("Adjacency Matrix:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
}

int main() {
    int ch;
    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d",&n);
    if(n>MAX || n<=0) {
        printf("Invalid number of vertices\n");
        return 1;
    }
    printf("1. Directed Graph\n2. Undirected Graph\nChoose: ");
    scanf("%d",&directed);
    directed = (directed == 1) ? 1 : 0;

    init();

    while(1) {
        printf("\n1.Add edge\n2.Print matrix\n3.Exit\nChoice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: addEdge(); break;
            case 2: printMat(); break;
            case 3: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
