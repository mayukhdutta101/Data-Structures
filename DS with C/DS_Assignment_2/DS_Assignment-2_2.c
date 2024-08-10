/*Write a C program to pass an array to a function using Call by Value,
 update the array values in the function, print the array 
 elements both in the function and in the calling function.*/

#include<stdio.h>

void callByValue(int arr[5]){
    int i;
    printf("\n Array inside function after updating:- \n");
    for(i=0;i<5;i++){
        arr[i]=8;
        printf("%d",arr[i]);
    }
}
void main(){
    int arr[5]= {1,2,3,4,5},i;
    printf("\nArray before function call:-\n");
    for(i=0;i<5;i++){
        printf("%d",arr[i]);
    }
    callByValue(arr);
    printf("\n Array after function call:-\n");
    for(i=0;i<5;i++){
        printf("%d",arr[i]);
    }
}