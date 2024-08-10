/*
Write a program to solve the tower of Hanoi problem using recursion.
*/

#include <stdio.h>

// Function to move a disk from source pole to destination pole
void toh(int n, char source, char destination, char auxiliary)
{
    if (n == 1)
    {  
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary pole
    toh(n - 1, source, auxiliary, destination);

    // Move the nth disk from source to destination pole
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move n-1 disks from auxiliary to destination pole
    toh(n - 1, auxiliary, destination, source);
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Invalid input. Please enter a positive number of disks.\n");
        return 1;
    }

    printf("Tower of Hanoi solution for %d disks:\n", n);
    toh(n, 'A', 'C', 'B');

    return 0;
}
