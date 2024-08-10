/*
Write a Menu driven C program to accomplish the following functionalities in Queue using
Linked List:
a. Insert an element into the queue using a Linked List (Enqueue Operation).
b. Delete an element from the queue using a Linked List (Dequeue Operation).
c. Return the value of the FRONT element of the queue (without deleting it from the
queue) using a Linked List (Peep operation).
d. Display the elements of a queue using a Linked List.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void iniQueue(struct Queue* queue) {
    queue->front = queue->rear = NULL;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int value) {
    struct Node* newNode = createNode(value);
    
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    
    printf("Enqueued: %d\n", value);
}

void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Dequeue operation failed.\n");
        return;
    }
    
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    
    printf("Dequeued: %d\n", temp->data);
    free(temp);
}

int peep(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Peep operation failed.\n");
        return -1;
    }
    
    return queue->front->data;
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    
    struct Node* current = queue->front;
    printf("Queue elements: ");
    
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    
    printf("\n");
}

int main() {
    struct Queue queue;
    iniQueue(&queue);
    int choice, element;
    
    do {
        printf("\nQueue Menu:\n1. Enqueue\n2. Dequeue\n3. Peep\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(&queue, element);
                break;
                
            case 2:
                dequeue(&queue);
                break;
                
            case 3:
                element = peep(&queue);
                if (element != -1)
                    printf("Front element: %d\n", element);
                break;
                
            case 4:
                display(&queue);
                break;
                
            case 5:
                printf("Exiting the program.\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}