//Write a C program to search an element in a BST and show the result

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

struct TreeNode* insertNode(struct TreeNode* root, int data) 
{
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

struct TreeNode* searchNode(struct TreeNode* root, int key) {

    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return searchNode(root->right, key);

    return searchNode(root->left, key);
}

void displaySearchResult(struct TreeNode* result, int key) {
    if (result == NULL) {
        printf("Element %d not found in the BST.\n", key);
    } else {
        printf("Element %d found in the BST.\n", key);
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

    int keyToSearch = 40; 
    struct TreeNode* searchResult = searchNode(root, keyToSearch);

    displaySearchResult(searchResult, keyToSearch);

    return 0;
}
