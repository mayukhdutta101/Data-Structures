/*
Write a program to evaluate a postfix expression.
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

// Function to evaluate a postfix expression
int evaluatePostfix(char *postfix)
{
    struct Stack *stack = createStack(MAX_SIZE);
    int i;

    for (i = 0; postfix[i]; ++i)
    {
        if (isdigit(postfix[i]))
        {
            push(stack, postfix[i] - '0');
        }
        else
        {
            int operand2 = pop(stack);
            int operand1 = pop(stack);

            switch (postfix[i])
            {
            case '+':
                push(stack, operand1 + operand2);
                break;
            case '-':
                push(stack, operand1 - operand2);
                break;
            case '*':
                push(stack, operand1 * operand2);
                break;
            case '/':
                push(stack, operand1 / operand2);
                break;
            }
        }
    }

    return pop(stack); // The final result will be on the top of the stack
}

int main()
{
    char postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);

    printf("Result of the postfix expression: %d\n", result);

    return 0;
}
