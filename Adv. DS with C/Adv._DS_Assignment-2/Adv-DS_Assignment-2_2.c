//Write a C program to create a binary tree using non-recursive function and display that level wise.

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct QueueNode {
    struct TreeNode *treeNode;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, struct TreeNode *root) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = root;
    temp->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        return;
    }
    queue->rear->next = temp;
    queue->rear = temp;
}

struct TreeNode* dequeue(struct Queue* queue) {
    if (queue->front == NULL)
        return NULL;
    struct TreeNode* temp = queue->front->treeNode;
    struct QueueNode* tempNode = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(tempNode);
    return temp;
}

int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

void printLevelOrder(struct TreeNode* root) {
    if (root == NULL)
        return;
    struct Queue* queue = createQueue();
    enqueue(queue, root);
    while (!isEmpty(queue)) {
        struct TreeNode* tempNode = dequeue(queue);
        printf("%d ", tempNode->data);
        if (tempNode->left != NULL)
            enqueue(queue, tempNode->left);
        if (tempNode->right != NULL)
            enqueue(queue, tempNode->right);
    }
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Level Order traversal of binary tree: ");
    printLevelOrder(root);
    printf("\n");
    return 0;
}
