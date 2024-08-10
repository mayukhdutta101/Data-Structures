//Write a C program to create a binary tree using array only and display the tree level wise.

#include <stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

struct TreeNode {
    int data;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    return newNode;
}

void printLevelOrder(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            printf("%d ", arr[i]);
    }
}

int main() {
    int tree[MAX_SIZE];
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array (-1 for empty): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
    }

    printf("Level Order traversal of binary tree: ");
    printLevelOrder(tree, n);
    printf("\n");

    return 0;
}
