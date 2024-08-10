/*
Write a Menu driven C program to accomplish the following functionalities in Stack using
Linked List:
a. Insert an element into the stack using a Linked List (Push Operation).
b. Delete an element from the stack using a Linked List (Pop Operation).
c. Return the value of the topmost element of the stack (without deleting it from the
stack) using a Linked List.
d. Display the elements of the stack using a Linked List.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int element)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = top;
    top = newNode;
    printf("Element %d pushed into the stack\n", element);
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
    }
    else
    {
        struct Node *temp = top;
        printf("Element %d popped from the stack\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");
        struct Node *current = top;
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        printf("Topmost element is: %d\n", top->data);
        return top->data;
    }
}

int main()
{
    int choice, element;

    while (1)
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &element);
            push(element);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
