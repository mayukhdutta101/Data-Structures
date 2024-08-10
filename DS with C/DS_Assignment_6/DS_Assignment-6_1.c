/*
Write a Menu driven C program to accomplish the following functionalities in Stack using
an Array:
a. Insert an element into the stack using an array (Push Operation).
b. Delete an element from the stack using an array (Pop Operation).
c. Return the value of the topmost element of the stack (without deleting it from the
stack) using an array.
d. Display the elements of a stack using an array.
*/

#include <stdio.h>
#include <stdlib.h>

#define max 10

int stack[max];
int top = -1;

void push(int element)
{
    if (top == max - 1)
    {
        printf("Stack Overflow! Cannot push element %d\n", element);
    }
    else
    {
        top++;
        stack[top] = element;
        printf("Element %d pushed into the stack\n", element);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
    }
    else
    {
        printf("Element %d popped from the stack\n", stack[top]);
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        printf("Topmost element is: %d\n", stack[top]);
        return stack[top];
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
