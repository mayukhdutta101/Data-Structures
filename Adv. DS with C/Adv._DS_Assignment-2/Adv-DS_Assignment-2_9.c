//Write a C program to count number of node present in a given binary tree using array.

#include <stdio.h>
#define MAX_SIZE 100

struct TreeNode {
    int data;
};

int countNodes(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            count++;
    }
    return count;
}

int main() {
    int tree[MAX_SIZE];
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array (-1 for empty): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
    }

    printf("Number of nodes in the binary tree: %d\n", countNodes(tree, n));

    return 0;
}
