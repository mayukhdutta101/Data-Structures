/* Write a C program to read a 2D array(with most of the elements as 0s) and 
then represent the same array as sparse matrix*/

#include<stdio.h>
void main(){
    int arr[10][10]={0},sparse[3][10]={0},i,j,m,n,k=0;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("Enter the element at [%d] [%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(arr[i][j] != 0){
                sparse[0][k]=i;
                sparse[1][k]=j;
                sparse[2][k]=arr[i][j];
                k++;
            }
        }
    }
    printf("Sparse Matrix:- \n");
    for(i=0;i<3;i++){
        for(j=0;j<k;j++){
        printf(" %d ",sparse[i][j]);
    }
    printf(" \n ");
    }
}