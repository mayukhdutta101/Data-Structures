/*
Write a Menu driven C program to accomplish the following functionalities in Queue using
an Array:
a. Insert an element into the queue using an array (Enqueue Operation).
b. Delete an element from the queue using an array (Dequeue Operation).
c. Return the value of the FRONT element of the queue (without deleting it from the
queue) using an array (Peep operation).
d. Display the elements of a queue using an array.
*/

#include <stdio.h>
#include <stdlib.h>

#define max 10

int queue[max];
int front = -1;
int rear = -1;

void enqueue(int element) {
    if (rear == max - 1) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = element;
        printf("Enqueued %d\n", element);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        int removed = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        printf("Dequeued %d\n", removed);
    }
}

void peep() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;
    printf("\nQueue Menu:\n1. Enqueue\n2. Dequeue\n3. Peep\n4. Display\n5. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peep();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}