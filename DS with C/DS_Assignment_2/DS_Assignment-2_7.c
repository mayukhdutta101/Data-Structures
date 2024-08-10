/*Write a program to allocate memory using calloc( ) and 
then reallocate the previously allocated memory using realloc(). 
Display the elements which have been taken after reallocation.*/
#include<stdio.h>
#include<stdlib.h>
void main(){
    int *arr,n,i,extra;
    printf("\nEnter size of array:-\n ");
    scanf("%d",&n);
    arr=(int *)calloc(n, sizeof(int));
    printf("\nEnter array elements: \n");
    for(i=0;i<n;i++){
        printf("Enter elements: ");
        scanf("%d",&arr[i]);
    }
    printf("\nArray Elements:-\n");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    printf("\nEnter the size to reallocate: ");
    scanf("%d",&extra);
    arr = realloc(arr,n+extra);
    printf("\nEnter array elements:-\n");
    for(i=n;i<n+extra;i++){
        printf("\nEnter element: ");
        scanf("%d",arr[i]);
    }
    printf("\nArray elements: \n");
    for(i=0;i<n+extra;i++){
        printf("%d",arr[i]);
    }
}