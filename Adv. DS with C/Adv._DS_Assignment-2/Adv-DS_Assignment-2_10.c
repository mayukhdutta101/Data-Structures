//Write a C program to count number of siblings present in a binary tree.

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

int countSiblings(struct TreeNode* root, int key) {
    if (root == NULL)
        return -1;
    if ((root->left != NULL && root->left->data == key) ||
        (root->right != NULL && root->right->data == key)) {
        if (root->left != NULL && root->right != NULL)
            return 2;
        else if (root->left != NULL || root->right != NULL)
            return 1;
        else
            return 0;
    }
    int leftSiblings = countSiblings(root->left, key);
    if (leftSiblings != -1)
        return leftSiblings;
    return countSiblings(root->right, key);
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    int key;
    printf("Enter the node to find its siblings: ");
    scanf("%d", &key);

    int siblingsCount = countSiblings(root, key);
    if (siblingsCount == -1)
        printf("Node not found in the tree or it's the root.\n");
    else
        printf("Number of siblings of node %d is: %d\n", key, siblingsCount);

    return 0;
}
