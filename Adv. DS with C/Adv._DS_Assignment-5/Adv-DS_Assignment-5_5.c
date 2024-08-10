//Write a C program to identify number of odd degree vertices and number of even degree vertices in a graph.

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int degree[MAX];

void initialize(int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        degree[i] = 0;
        for (int j = 0; j < numVertices; j++) {
            adj[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; 
    degree[u]++;
    degree[v]++;
}

int countOddDegreeVertices(int numVertices) {
    int count = 0;
    for (int i = 0; i < numVertices; i++) {
        if (degree[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

int countEvenDegreeVertices(int numVertices) {
    int count = 0;
    for (int i = 0; i < numVertices; i++) {
        if (degree[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int numVertices, numEdges;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    
    initialize(numVertices);
    
    printf("Enter the edges:\n");
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    
    int oddDegreeVertices = countOddDegreeVertices(numVertices);
    int evenDegreeVertices = countEvenDegreeVertices(numVertices);
    
    printf("Number of odd degree vertices: %d\n", oddDegreeVertices);
    printf("Number of even degree vertices: %d\n", evenDegreeVertices);
    
    return 0;
}
