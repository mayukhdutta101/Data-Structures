//Write a C program to create a binary tree using recursive function and display that level wise.

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

    if (root->left == NULL) {
        root->left = insertNode(root->left, data);
    } else if (root->right == NULL) {
        root->right = insertNode(root->right, data);
    } else {
        root->left = insertNode(root->left, data);
    }
    return root;
}

void printGivenLevel(struct TreeNode* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

int height(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

void printLevelOrder(struct TreeNode* root) {
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i);
}

int main() {
    struct TreeNode* root = NULL;

    root = insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);

    printf("Level Order traversal of binary tree: ");
    printLevelOrder(root);
    printf("\n");

    return 0;
}
