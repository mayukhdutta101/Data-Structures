//Write a C program to store the following Graph using Adjacency List & display that.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char vertex;
    int weight;
    struct Node* next;
};

struct Node* createNode(char vertex, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adjList[], char src, char dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = adjList[src - 'P'];
    adjList[src - 'P'] = newNode;
}

void displayGraph(struct Node* adjList[], int numVertices) {
    printf("Adjacency List Representation of the Graph:\n");
    for (int i = 0; i < numVertices; ++i) {
        printf("%c -> ", 'P' + i);
        struct Node* temp = adjList[i];
        while (temp) {
            printf("%c (%d) ", temp->vertex, temp->weight);
            temp = temp->next;
            if (temp)
                printf("-> ");
        }
        printf("\n");
    }
}

int main() {
    int numVertices = 6;
    struct Node* adjList[numVertices];
    for (int i = 0; i < numVertices; ++i)
        adjList[i] = NULL;

    addEdge(adjList, 'P', 'Q', 1);
    addEdge(adjList, 'P', 'T', 7);
    addEdge(adjList, 'P', 'S', 6);
    addEdge(adjList, 'Q', 'S', 4);
    addEdge(adjList, 'Q', 'R', 1);
    addEdge(adjList, 'T', 'U', 2);
    addEdge(adjList, 'S', 'T', 3);
    addEdge(adjList, 'S', 'U', 2);
    addEdge(adjList, 'R', 'S', 2);
    addEdge(adjList, 'R', 'U', 1);

    displayGraph(adjList, numVertices);

    return 0;
}
