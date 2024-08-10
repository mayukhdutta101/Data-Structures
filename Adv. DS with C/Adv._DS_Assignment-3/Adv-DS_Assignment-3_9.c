//Write a C program to prove that binary search tree is better than binary tree.

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

int main() {
    struct TreeNode* rootBST = NULL;
    struct TreeNode* rootBT = NULL;
    int i;

    for (i = 1; i <= 10000; i++) {
        rootBST = insertNode(rootBST, i);
    }

    for (i = 1; i <= 10000; i++) {
        rootBT = insertNode(rootBT, rand() % 10000 + 1);
    }

    return 0;
}
