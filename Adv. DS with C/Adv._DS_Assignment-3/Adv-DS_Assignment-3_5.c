//Write a C program to take user name as input and display the sorted sequence of characters using BST.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, char data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
 

    return root;
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%c", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    char name[100];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    for (int i = 0; name[i] != '\0'; i++) {
        name[i] = toupper(name[i]);
    }

    struct TreeNode* root = NULL;

    for (int i = 0; name[i] != '\0'; i++) {
        if (isalpha(name[i])) { 
            root = insertNode(root, name[i]);
        }
    }

    printf("Sorted sequence of characters in your name: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
