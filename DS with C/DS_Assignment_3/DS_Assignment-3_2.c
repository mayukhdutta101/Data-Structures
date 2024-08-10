/*
Write a Menu driven C program to accomplish the following functionalities in circular
linked list.
a) Create a circular linked list.
b) Display the elements of a circular linked list.
c) Insert a node at the beginning of a circular linked list.
d) Insert a node at the end of a circular linked list.
e) Delete a node from the beginning of a circular linked list.
f) Delete a node from the end of a circular linked list.
g) Delete a node after a given node of a circular linked list.
h) Delete the entire circular linked list.
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
    {
        head = newnode;
        head->next = head;
    }

    else
    {
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = newnode;
        newnode->next = head;
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
        while (ptr->next != head)
        {
            
               printf("%d", ptr->data);
            ptr = ptr->next;
        }
        printf("%d", ptr->data);
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
    {
        head = newnode;
        head->next = head;
    }
    else
    {
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = newnode;
        newnode->next = head;
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
    {
        head = newnode;
        head->next = head;
    }
    else
    {
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = newnode;
        newnode->next = head;
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
    else if (ptr->next == head)
    {
        free(ptr);
        head = NULL;
    }

    else
    {
        while (ptr->next != head)
            ptr = ptr->next;
        head = head->next;
        free(ptr->next);
        ptr->next = head;
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
    else if (ptr->next == head)
    {
        free(ptr);
        head = NULL;
    }
    else
    {
        while (ptr->next->next != head)
            ptr = ptr->next;
        free(ptr->next);
        ptr->next = head;
    }
}

void DeleteAfter(int pos)
{
    struct node *ptr = head;
    struct node *ptr1;
    if (ptr == NULL)
        printf("Linked list is empty \n");
    else if (ptr->next == head && ptr->data == pos)
        printf("No element after %d so element cannot be deleted \n", ptr->data);
    else if (ptr->next == head && ptr->data != pos)
        printf("Element not present in the linked list after which node has to be deleted\n");
    else
    {
        while (ptr->data != pos && ptr->next != head)
            ptr = ptr->next;
        if (ptr->next == head && ptr->data == pos)
        {
            head = head->next;
            free(ptr->next);
            ptr->next = head;
        }
        else if (ptr->next == head && ptr->data != pos)
            printf("Element not present in the linked list after which node has to be deleted\n");
        else
        {
            if (ptr->next->next == head)
            {
                free(ptr->next);
                ptr->next = head;
            }
            else
            {
                ptr1 = ptr->next;
                ptr->next = ptr->next->next;
                free(ptr1);
            }
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
        while (ptr->next != head)
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
        printf("Enter 1 to insert at the beginning \nEnter 2 to insert at the end \nEnter 3 to delete at the beginning\nEnter 4 to delete at the end \nEnter 5 to delete after an element \nEnter 6 to delete the whole linked list\nEnter your choice \n");
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
            printf("Deleting the element at the beginning \n");
            DeleteBegin();
            DisplayList();
            break;
        }
        case 4:
        {
            printf("Deleting the element at the end \n");
            DeleteEnd();
            DisplayList();
            break;
        }
        case 5:
        {
            printf("Enter the element after which the node has to be deleted \n");
            scanf("%d", &y);
            DeleteAfter(y);
            DisplayList();
            break;
        }
        case 6:
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