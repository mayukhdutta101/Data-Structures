/* Write a program that reads a 2D metrics and checks if the metrics is a symmetric 
metrics or not
*/
#include <stdio.h>

int isSymmetric(int mat[][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != mat[j][i]) {
                return 0; // Not symmetric
            }
        }
    }
    return 1; // Symmetric
}

int main() {
    int mat[][3] = {{1, 2, 3}, {2, 4, 5}, {3, 5, 6}};
    int n = 3;

    if (isSymmetric(mat, n)) {
        printf("Matrix is symmetric.\n");
    } else {
        printf("Matrix is not symmetric.\n");
    }

    return 0;
}
