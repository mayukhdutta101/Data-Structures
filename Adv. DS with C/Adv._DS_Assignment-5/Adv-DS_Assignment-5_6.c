//Write a C program to check whether a given graph is complete or not.

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];

int isCompleteGraph(int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i != j && adj[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

int main() {
    int numVertices, numEdges;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adj[i][j] = 0;
        }
    }
    
    printf("Enter the edges:\n");
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }
    
    if (isCompleteGraph(numVertices))
        printf("The graph is complete.\n");
    else
        printf("The graph is not complete.\n");
    
    return 0;
}
