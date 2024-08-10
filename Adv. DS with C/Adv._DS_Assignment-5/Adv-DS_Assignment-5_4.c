//Write a C program to detect a cycle in a graph.

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

int isCyclicUtil(int v, int parent, int numVertices) {
    visited[v] = 1;
    for (int i = 0; i < numVertices; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (isCyclicUtil(i, v, numVertices))
                    return 1;
            } else if (i != parent)
                return 1;
        }
    }
    return 0;
}

int isCyclic(int numVertices) {
    for (int i = 0; i < numVertices; i++)
        visited[i] = 0;
    
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, -1, numVertices))
                return 1;
        }
    }
    return 0;
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
    
    if (isCyclic(numVertices))
        printf("Graph contains cycle.\n");
    else
        printf("Graph doesn't contain cycle.\n");
    
    return 0;
}
