/* Write a program that reads two 2D metrices from the console, verifies if metrics
multiplication is possible or not. Then multiplies the metrices and prints the 3rd metrics.*/

#include <stdio.h>
void matrixMultiplication(int mat1[][3], int rows1, int cols1, int mat2[][2], int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible.\n");
        return;
    }

    int result[rows1][cols2];
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("Resultant matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int mat1[][3] = {{1, 2, 3}, {4, 5, 6}};
    int rows1 = 2, cols1 = 3;

    int mat2[][2] = {{1, 2}, {3, 4}, {5, 6}};
    int rows2 = 3, cols2 = 2;

    matrixMultiplication(mat1, rows1, cols1, mat2, rows2, cols2);

    return 0;
}
