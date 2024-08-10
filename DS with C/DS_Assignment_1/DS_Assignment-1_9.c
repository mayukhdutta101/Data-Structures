// Write a C program to print reverse array

#include <stdio.h>

void ReverseArray(int arr[] , int size){
    printf("Reverse Array: ");
    for(int i= size-1; i>=0;i--){
        printf("%d",arr[i]);
    }
}
int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    ReverseArray(arr , size);
    return 0;
}