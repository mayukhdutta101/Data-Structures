//Write a C program to identify degree of a given node.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

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

int degree(struct TreeNode* root, int key) {
    if (root == NULL)
        return -1;
    if (root->data == key) {
        if (root->left != NULL && root->right != NULL)
            return 2;
        else if (root->left != NULL || root->right != NULL)
            return 1;
        else
            return 0;
    }
    int leftDegree = degree(root->left, key);
    if (leftDegree != -1)
        return leftDegree;
    return degree(root->right, key);
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    int key;
    printf("Enter the node to find its degree: ");
    scanf("%d", &key);

    int nodeDegree = degree(root, key);
    if (nodeDegree == -1)
        printf("Node not found in the tree.\n");
    else
        printf("Degree of node %d is: %d\n", key, nodeDegree);

    return 0;
}
