//Write a C program to show that Quick sort is better than Bubble sort.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int n = 10000;
    int arr1[n], arr2[n];

    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 10000;
        arr2[i] = arr1[i];
    }

    clock_t start, end;

    start = clock();
    quickSort(arr1, 0, n - 1);
    end = clock();
    printf("Time taken by Quick Sort: %lf seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    start = clock();
    bubbleSort(arr2, n);
    end = clock();
    printf("Time taken by Bubble Sort: %lf seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    return 0;
}
