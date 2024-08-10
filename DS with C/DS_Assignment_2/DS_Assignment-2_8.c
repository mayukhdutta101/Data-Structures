/*Write a C program to search an element in an Array 
 using dynamic memory allocation.*/

#include<stdio.h>
#include<stdlib.h>
int main(){
    int *arr,n,i,key;
    printf("\nEnter the size of array: ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    printf("\nEnter array elements:-\n");
    for(i=0;i<n;i++){
        printf("Enter element:");
        scanf("%d",&arr[i]);
    }
    printf("\nEnter search key: ");
    scanf("%d",&key);
    for(i=0;i<n;i++){
        if(*(arr+i)==key){
            printf("\nKey found at index %d",i);
            return 0;
        }
    }
    printf("\n Key not found.");
    return 0;
}
