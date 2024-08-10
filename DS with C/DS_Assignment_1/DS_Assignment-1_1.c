// Write a C program to print an array.
#include<stdio.h>
int main()
{
    int arr[10],i;
    printf("Enter the array: ");
    for(i = 0; i < 10; i++){
    scanf("%d",&arr[i]);
    }
    
    for(i = 0; i < 10; i++)
    {
        printf("The given array is : %d\n",arr[i]);
    }
    return 0;
}
