/*
Write a program to convert an infix expression into its equivalent prefix notation.
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

// Function to reverse a string
void reverseString(char *str)
{
    int length = strlen(str);
    int i, j;
    for (i = 0, j = length - 1; i < j; ++i, --j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to convert infix expression to prefix notation
void infixToPrefix(char *infix, char *prefix)
{
    struct Stack *stack = createStack(MAX_SIZE);
    int i, j;

    reverseString(infix);

    for (i = 0, j = 0; infix[i]; ++i)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    for (i = 0; infix[i]; ++i)
    {
        if (isOperand(infix[i]))
            prefix[j++] = infix[i];
        else if (infix[i] == '(')
            push(stack, infix[i]);
        else if (infix[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                prefix[j++] = pop(stack);
            pop(stack); // Pop '(' from the stack
        }
        else
        {
            while (!isEmpty(stack) && precedence(infix[i]) < precedence(peek(stack)))
                prefix[j++] = pop(stack);
            push(stack, infix[i]);
        }
    }

    // Pop remaining operators from the stack
    while (!isEmpty(stack))
        prefix[j++] = pop(stack);

    prefix[j] = '\0'; // Null-terminate the output string
    reverseString(prefix);
}

int main()
{
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
