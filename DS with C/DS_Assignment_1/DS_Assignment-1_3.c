// Write a C program to convert temperature from degree Centigrade to Fahrenheit.
#include<stdio.h>
int main()
{
    float c,f;
    printf("Enter temparature in Celcius: ");
    scanf("%f",&c);
    f = (c * 1.8) + 32;
    printf("The temperature in Farenheit is: %.2f",f);
    return 0;
}