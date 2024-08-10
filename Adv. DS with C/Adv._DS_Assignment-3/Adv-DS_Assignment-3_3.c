//Write a C program to insert (by using a function) a specific element into an existing binary search tree and then display that.

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

    if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
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

    int elementToInsert = 45; 
    root = insertNode(root, elementToInsert);

    printf("Binary Search Tree elements after inserting %d: ", elementToInsert);
    inorderTraversal(root);
    printf("\n");

    return 0;
}
