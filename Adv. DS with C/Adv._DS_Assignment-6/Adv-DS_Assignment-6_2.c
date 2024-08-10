//Write a C program to traverse the following graph using Breadth First Search (BFS) algorithm

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

struct Queue {
    int items[MAX];
    int front;
    int rear;
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

void enqueue(struct Queue* queue, int vertex) {
    queue->rear++;
    queue->items[queue->rear] = vertex;
}

int dequeue(struct Queue* queue) {
    int item = queue->items[queue->front];
    queue->front++;
    return item;
}

int isEmpty(struct Queue* queue) {
    return queue->rear == queue->front - 1;
}

void bfs(struct Graph* graph, int start) {
    struct Queue queue;
    queue.front = 0;
    queue.rear = -1;

    graph->vertices[start].visited = 1;
    enqueue(&queue, start);

    while (!isEmpty(&queue)) {
        int current = dequeue(&queue);
        printf("%c ", current + 'P');

        struct Edge* edge = graph->vertices[current].edges;
        while (edge != NULL) {
            int dest = edge->dest;
            if (!graph->vertices[dest].visited) {
                graph->vertices[dest].visited = 1;
                enqueue(&queue, dest);
            }
            edge = edge->next;
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

    printf("Breadth First Traversal starting from P: ");
    bfs(&graph, 0);  
    printf("\n");

    return 0;
}
