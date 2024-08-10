//Write a C program to traverse the following graph using Depth First Search (DFS) algorithm

#include <stdio.h>
#include <stdlib.h>

#define MAX 6

struct Edge {
    int dest;
    int weight;
    struct Edge* next;
};

struct Vertex {
    int visited;
    struct Edge* edges;
};

struct Graph {
    struct Vertex vertices[MAX];
};

struct Stack {
    int items[MAX];
    int top;
};

void initGraph(struct Graph* graph) {
    for (int i = 0; i < MAX; ++i) {
        graph->vertices[i].visited = 0;
        graph->vertices[i].edges = NULL;
    }
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = graph->vertices[src].edges;
    graph->vertices[src].edges = newEdge;
}

void push(struct Stack* stack, int vertex) {
    stack->items[++stack->top] = vertex;
}

int pop(struct Stack* stack) {
    return stack->items[stack->top--];
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void dfs(struct Graph* graph, int start) {
    struct Stack stack;
    stack.top = -1;

    push(&stack, start);

    while (!isEmpty(&stack)) {
        int current = pop(&stack);

        if (!graph->vertices[current].visited) {
            printf("%c ", current + 'P');
            graph->vertices[current].visited = 1;

            struct Edge* edge = graph->vertices[current].edges;
            while (edge != NULL) {
                if (!graph->vertices[edge->dest].visited) {
                    push(&stack, edge->dest);
                }
                edge = edge->next;
            }
        }
    }
}

int main() {
    struct Graph graph;
    initGraph(&graph);

    addEdge(&graph, 0, 1, 1);  // P -> Q = 1
    addEdge(&graph, 0, 2, 7);  // P -> T = 7
    addEdge(&graph, 0, 3, 6);  // P -> S = 6
    addEdge(&graph, 1, 3, 4);  // Q -> S = 4
    addEdge(&graph, 1, 4, 1);  // Q -> R = 1
    addEdge(&graph, 2, 5, 2);  // T -> U = 2
    addEdge(&graph, 3, 2, 3);  // S -> T = 3
    addEdge(&graph, 3, 5, 2);  // S -> U = 2
    addEdge(&graph, 4, 3, 2);  // R -> S = 2
    addEdge(&graph, 4, 5, 1);  // R -> U = 1

    printf("Depth First Traversal starting from P: ");
    dfs(&graph, 0);  // Start DFS from P (index 0)
    printf("\n");

    return 0;
}
