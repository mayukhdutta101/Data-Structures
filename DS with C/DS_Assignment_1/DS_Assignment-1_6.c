// Write a C program to display Fibonacci series
#include<stdio.h>
void isFibonacci(int n){
    int a=0, b=1;
    printf("Fibonacci series is: %d %d ",a,b);
    for(int i=2;i<n;i++){
        int c = a+b;
        printf("%d ",c);
        a=b;
        b=c;
    }
}
int main(){
    int n;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    isFibonacci(n);
    return 0;
}