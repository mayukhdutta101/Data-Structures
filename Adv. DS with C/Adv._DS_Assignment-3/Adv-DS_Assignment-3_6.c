//Write a C program to sort a given set of integers using BST.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorderTraversalToArray(struct TreeNode* root, int *array, int *index) {
    if (root != NULL) {
        inorderTraversalToArray(root->left, array, index);
        array[(*index)++] = root->data;
        inorderTraversalToArray(root->right, array, index);
    }
}

void sortUsingBST(int *arr, int n) {
    struct TreeNode* root = NULL; 

    for (int i = 0; i < n; i++) {
        root = insertNode(root, arr[i]);
    }

    int index = 0;
    inorderTraversalToArray(root, arr, &index);
}

int main() {
    int arr[] = {12, 5, 7, 3, 19, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    sortUsingBST(arr, n);

    printf("Sorted array using BST: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
