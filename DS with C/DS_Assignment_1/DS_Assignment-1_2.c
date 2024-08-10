// Write a C program to check whether a given string is Palindrome or not.
#include<stdio.h>
#include<string.h>

int isPalindrome(char str[]){
    int length = strlen(str);
    for(int i=0; i< length / 2; i++){
        if(str[i] != str[length - i - 1]){
            return 0; //not a Palindrome
        }
        else {
            return 1; //is a Palindrome
        }
    }
}
int main(){
    char str[1000];
    printf("Enter a string: ");
    scanf("%s",str);
    
    if(isPalindrome(str)){
        printf("Palindrome\n");
    }
    else{
        printf("Not a Palindrome");
    }
    return 0;
}