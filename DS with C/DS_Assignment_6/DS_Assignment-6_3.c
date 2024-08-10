/*
Write a program to convert an infix expression into its equivalent postfix notation.
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
    char *array;
};

// Function to create a stack of given capacity
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, char item)
{
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$'; // Return a special character to indicate an empty stack
}

// Function to return the top element of the stack without popping it
char peek(struct Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top];
    return '$'; // Return a special character to indicate an empty stack
}

// Function to check if a character is an operand
int isOperand(char ch)
{
    return isalnum(ch);
}

// Function to determine the precedence of an operator
int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

// Function to convert infix expression to postfix notation
void infixToPostfix(char *infix)
{
    struct Stack *stack = createStack(MAX_SIZE);
    int i, j;

    for (i = 0, j = 0; infix[i]; ++i)
    {
        // If the scanned character is an operand, add it to the output
        if (isOperand(infix[i]))
            infix[j++] = infix[i];
        // If the scanned character is an '(', push it onto the stack
        else if (infix[i] == '(')
            push(stack, infix[i]);
        // If the scanned character is an ')', pop and output from the stack until an '(' is encountered
        else if (infix[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                infix[j++] = pop(stack);
            pop(stack); // Pop '(' from the stack
        }
        // If the scanned character is an operator
        else
        {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
                infix[j++] = pop(stack);
            push(stack, infix[i]);
        }
    }

    // Pop all the remaining operators from the stack
    while (!isEmpty(stack))
        infix[j++] = pop(stack);

    infix[j] = '\0'; // Null-terminate the output string
}

int main()
{
    char infix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    printf("Postfix expression: %s\n", infix);

    return 0;
}
