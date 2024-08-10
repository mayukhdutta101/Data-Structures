//Write a C program to create a binary search tree using non-recursive function and display that

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

    struct TreeNode* current = root;
    struct TreeNode* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data <= current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (data <= parent->data) {
        parent->left = createNode(data);
    } else {
        parent->right = createNode(data);
    }

    return root;
}

void inorderTraversal(struct TreeNode* root) {
    struct TreeNode* stack[100]; 
    int top = -1;

    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    struct TreeNode* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);

        current = current->right;
    }
}

int main() {
    struct TreeNode* root = NULL;

    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Binary Search Tree elements in inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
