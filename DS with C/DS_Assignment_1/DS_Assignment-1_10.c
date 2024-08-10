// Write a C program to check the sum of all elements of an array
#include <stdio.h>

int main(){
    
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    for(int i=0; i<size; i++){
        sum += arr[i];
    }
    printf("The sum of the arrays: %d\n", sum);
    
    return 0;
}