/*
Write a program to evaluate a prefix expression.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

// Function to create a stack of given capacity
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int item)
{
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return -1; // Return a special value to indicate an empty stack
}

// Function to evaluate a prefix expression
int evaluatePrefix(char *prefix)
{
    struct Stack *stack = createStack(MAX_SIZE);
    int i, operand;

    for (i = strlen(prefix) - 1; i >= 0; --i)
    {
        if (isdigit(prefix[i]))
        {
            push(stack, prefix[i] - '0');
        }
        else
        {
            int operand1 = pop(stack);
            int operand2 = pop(stack);

            switch (prefix[i])
            {
            case '+':
                operand = operand1 + operand2;
                break;
            case '-':
                operand = operand1 - operand2;
                break;
            case '*':
                operand = operand1 * operand2;
                break;
            case '/':
                operand = operand1 / operand2;
                break;
            }

            push(stack, operand);
        }
    }

    return pop(stack); // The final result will be on the top of the stack
}

int main()
{
    char prefix[MAX_SIZE];

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    int result = evaluatePrefix(prefix);

    printf("Result of the prefix expression: %d\n", result);

    return 0;
}
