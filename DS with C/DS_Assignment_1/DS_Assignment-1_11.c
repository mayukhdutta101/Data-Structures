// Write a C program to check duplicate number in an array.

#include <stdio.h>

int hasDuplicate(int arr[] , int size){
    for(int i=0;i<size;i++){
        for(int j= i+1;j<size;j++){
            if(arr[i] == arr[j]){
                return 1; //Duplicate Found
            }
        }
    }
    return 0; // No Duplicate Found
}

int main(){
    int arr[] = {1,2,8,4,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    if (hasDuplicate(arr,size)){
        printf("Array contains duplicate number. \n");
    }
    else {
        printf("Array does not contain duplicate number. \n");
    }
    return 0;
}