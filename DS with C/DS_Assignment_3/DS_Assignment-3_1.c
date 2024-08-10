/*
Write a Menu driven C program to accomplish the following functionalities in single
linked list.
a) Create a single linked list.
b) Display the elements of a single linked list.
c) Insert a node at the beginning of a single linked list.
d) Insert a node at the end of a single linked list.
e) Insert a node before a given node of a single linked list.
f) Insert a node after a given node of a single linked list.
g) Delete a node from the beginning of a single linked list.
h) Delete a node from the end of a single linked list.
i) Delete a node after a given node of a single linked list.
j) Delete the entire single linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void AddNewNode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    struct node *ptr = head;
    if (ptr == NULL)
        head = newnode;
    else
    {
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newnode;
    }
}

void DisplayList()
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("List is empty \n");
        return;
    }
    else
    {

        printf("The data of the single linked list: \n");
        while (ptr != NULL)
        {
            if (ptr->next != NULL)
                printf("%d,", ptr->data);
            else
                printf("%d", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void InsertBegin(int data)
{
    struct node *ptr = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (ptr == NULL)
        head = newnode;
    else
    {
        newnode->next = ptr;
        head = newnode;
    }
}

void InsertEnd(int data)
{
    struct node *ptr = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (ptr == NULL)
        head = newnode;
    else
    {
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newnode;
    }
}

void InsertBefore(int data, int pos)
{
    struct node *ptr = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (ptr == NULL)
        head = newnode;
    else if (ptr->data == pos)
    {
        newnode->next = ptr;
        head = newnode;
    }
    else if (ptr->data != pos && ptr->next == NULL)
        printf("Element not in the linked list before which the new node has to be inserted\n");
    else
    {
        while (ptr->next->data != pos && ptr->next->next != NULL)
            ptr = ptr->next;
        if (ptr->next->data == pos)
        {
            newnode->next = ptr->next;
            ptr->next = newnode;
        }
        else
            printf("Element not in the linked list before which the new node has to be inserted\n");
    }
}

void InsertAfter(int data, int pos)
{
    struct node *ptr = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (ptr == NULL)
        head = newnode;

    else
    {
        while (ptr->data != pos && ptr->next != NULL)
            ptr = ptr->next;
        if (ptr->data == pos)
        {
            newnode->next = ptr->next;
            ptr->next = newnode;
        }
        else
            printf("Element not present in the linked list after which the new node has to be inserted\n");
    }
}

void DeleteBegin()
{
    struct node *ptr = head;

    if (ptr == NULL)
    {
        printf("The linked list is empty \n");
        return;
    }

    else
    {
        head = ptr->next;
        free(ptr);
    }
}

void DeleteEnd()
{
    struct node *ptr = head;

    if (ptr == NULL)
    {
        printf("The linked list is empty \n");
        return;
    }

    else
    {
        while (ptr->next->next != NULL)
            ptr = ptr->next;
        free(ptr->next);
        ptr->next = NULL;
    }
}

void DeleteAfter(int pos)
{
    struct node *ptr = head;
    struct node *ptr1;

    if (ptr == NULL)
        printf("Linked list is empty \n");
    else if (ptr->data == pos)
    {
        ptr1 = ptr->next;
        ptr->next = ptr->next->next;
        free(ptr1);
    }
    else
    {
        while (ptr->data != pos && ptr->next != NULL)
            ptr = ptr->next;
        if (ptr->next == NULL && ptr->data == pos)
            printf("No element present after %d so element cannot be deleted\n", ptr->data);
        else if (ptr->next == NULL && ptr->data != pos)
            printf("Element not present in the linked list after which node has to be deleted\n");
        else
        {
            ptr1 = ptr->next;
            ptr->next = ptr->next->next;
            free(ptr1);
        }
    }
}

void DeleteComplete()
{
    struct node *ptr = head;
    struct node *ptr1;

    if (ptr == NULL)
        printf("Linked list is empty \n");

    else
    {
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
            free(ptr1);
        }
        head = NULL;
    }
}

int main()
{
    int n, x, i, c, y;
    printf("Enter the number of elements of the linked list \n");
    scanf("%d", &n);
    printf("Create the linked list by entering the elements \n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        AddNewNode(x);
    }
    DisplayList();
    while (head != NULL)
    {
        printf("Enter 1 to insert at the beginning \n");
        printf("Enter 2 to insert at the end \n");
        printf("Enter 3 to insert before an element \n");
        printf("Enter 4 to insert after an element\n");
        printf("Enter 5 to delete at the beginning\n");
        printf("Enter 6 to delete at the end \n");
        printf("Enter 7 to delete after an element \n");
        printf("Enter 8 to delete the whole linked list\n");
        printf("Enter your choice \n");
        scanf("%d", &c);
        switch (c)
        { 
        case 1:
        {
            printf("Enter the element to be inserted at the beginning \n");
            scanf("%d", &x);
            InsertBegin(x);
            DisplayList();
            break;
        }
        case 2:
        {
            printf("Enter the element to be inserted at the end \n");
            scanf("%d", &x);
            InsertEnd(x);
            DisplayList();
            break;
        }
        case 3:
        {
            printf("Enter the element before which the new node has to be inserted \n");
            scanf("%d", &y);
            printf("Enter the element to be inserted \n");
            scanf("%d", &x);
            InsertBefore(x, y);
            DisplayList();
            break;
        }
        case 4:
        {
            printf("Enter the element after which the new node has to be inserted \n");
            scanf("%d", &y);
            printf("Enter the element to be inserted \n");
            scanf("%d", &x);
            InsertAfter(x, y);
            DisplayList();
            break;
        }
        case 5:
        {
            printf("Deleting the element at the beginning \n");
            DeleteBegin();
            DisplayList();
            break;
        }
        case 6:
        {
            printf("Deleting the element at the end \n");
            DeleteEnd();
            DisplayList();
            break;
        }
        case 7:
        {
            printf("Enter the element after which the node has to be deleted \n");
            scanf("%d", &y);
            DeleteAfter(y);
            DisplayList();
            break;
        }
        case 8:
        {
            printf("Deleting the complete linked list \n");
            DeleteComplete();
            DisplayList();
            break;
        }
        default:
        {
            printf("Enter a valid choice \n");
        }
        }
    }
    return 0;
}