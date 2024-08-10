/*
Write a Menu driven C program to accomplish the following functionalities in Circular
Queue using Array:
a. Insert an element into the circular queue.
b. Delete an element from the circular queue.
c. Return the value of the FRONT element of the circular queue (without deleting it
from the queue).
d. Display the elements of a circular queue.
*/

#include <stdio.h>
#include <stdlib.h>

#define max 10

int circularQueue[max];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == max - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void insertElement(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot insert.\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (rear == max - 1) {
            rear = 0;
        } else {
            rear++;
        }
        circularQueue[rear] = item;
        printf("Inserted %d into the queue.\n", item);
    }
}

void deleteElement() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete.\n");
    } else {
        int delItem = circularQueue[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == max - 1) {
            front = 0;
        } else {
            front++;
        }
        printf("Deleted %d from the queue.\n", delItem);
    }
}

int frontElement() {
    if (isEmpty()) {
        printf("Queue is empty. No front element.\n");
        return -1;
    } else {
        return circularQueue[front];
    }
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements in the queue: ");
        int i = front;
        do {
            printf("%d ", circularQueue[i]);
            if (i == rear && front != rear) {
                break;
            }
            if (i == max - 1) {
                i = 0;
            } else {
                i++;
            }
        } while (i != front);
        printf("\n");
    }
}

int main() {
    int choice, item;
    printf("\nMenu:\n1. Insert an element\n2. Delete an element\n3. Front element\n4. Display queue\n5. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &item);
                insertElement(item);
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                printf("Front element: %d\n", frontElement());
                break;
            case 4:
                displayQueue();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}