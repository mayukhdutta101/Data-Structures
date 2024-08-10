// Write a C program to sort an array.
#include<stdio.h>
int main(){
    int num[20];
    int i,j,a,n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for(i=0;i<n;++i){
        scanf("%d",&num[i]);
    }
    for(i=0;i<n;++i){
        for(j=i+1;j<n;++j){
            if(num[i]>num[j]){
                a=num[i];
                num[i]=num[j];
                num[j]=a;
            }
        }
    }
    printf("The sorted array is: ");
    for(i=0;i<n;++i){
        printf("%d ",num[i]);
    }
    return 0;
}