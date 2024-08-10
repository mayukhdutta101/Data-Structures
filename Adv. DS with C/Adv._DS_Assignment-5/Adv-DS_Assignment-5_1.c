//Write a C program to store the following Graph using Adjacency Matrix &  display that.

#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES] = {0};

int main() {
    int num_vertices = 6; 
    graph['P' - 'A']['Q' - 'A'] = 1;
    graph['P' - 'A']['T' - 'A'] = 7;
    graph['P' - 'A']['S' - 'A'] = 6;
    graph['Q' - 'A']['S' - 'A'] = 4;
    graph['Q' - 'A']['R' - 'A'] = 1;
    graph['T' - 'A']['U' - 'A'] = 2;
    graph['S' - 'A']['T' - 'A'] = 3;
    graph['S' - 'A']['U' - 'A'] = 2;
    graph['R' - 'A']['S' - 'A'] = 2;
    graph['R' - 'A']['U' - 'A'] = 1;

    printf("Adjacency Matrix Representation of the Graph:\n");
    printf("  ");
    for (int i = 0; i < num_vertices; ++i)
        printf("%c ", 'A' + i);
    printf("\n");
    for (int i = 0; i < num_vertices; ++i) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < num_vertices; ++j) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}

