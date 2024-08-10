//Write a C program to implement the concept of Bubble sort on the above data set. Print the data set after every iteration.

#include<stdio.h>
int main(){
    int arr[]={27,15,39,21,28,70};
    int i,j,swap;
    printf("Original Dataset: ");
    for(i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    for(i=0;i<6;i++){
        for(j=i+1;j<6;j++){
            if(arr[i]>arr[j]){
                swap=arr[i];
                arr[i]=arr[j];
                arr[j]=swap;
            }
        }
        printf("After %d iteration: ",i);
        for(int k=0;k<6;k++){
        printf("%d ",arr[k]);
    } 
    printf("\n");
    }
    printf("After sorting: ");
    for(i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}