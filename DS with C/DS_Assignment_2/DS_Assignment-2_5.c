/*Write a program to display n number of elements. 
Memory should be allocated dynamically using calloc( ).*/

#include<stdio.h>
#include<stdlib.h>
void main(){
    int *arr,n,i;
    printf("Enter the size of array:-\n");
    scanf("%d",&n);
    arr = (int *)calloc(n, sizeof(int));
    printf("\nEnter array elements:-\n");
    for(i=0;i<n;i++){
        printf("\nEnter elements: ");
        scanf("%d",&arr[i]);
    }
    printf("\nArray elements: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}