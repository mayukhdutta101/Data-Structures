// Write a C program to print the largest and second largest element of the array
#include<stdio.h>
void findLargestandSecondLargest (int size, int arr[])
{
  int largest = arr[0];
  int secondLargest = arr[0];
  int i;
  for (i = 1; i < size; i++)
    {
      if (arr[i] > largest)
	{
	  secondLargest = largest;
	  largest = arr[i];
	}
      else if (arr[i] > secondLargest && arr[i] != largest)
	{
	  secondLargest = arr[i];
	}
    }

  printf ("Largest: %d\n", largest);
  printf ("Second Largest: %d\n", secondLargest);
}

int main ()
{
  int arr[] = { 5, 8, 91, 87, 42, 38, 105, 74, 15 };
  int size = sizeof(arr) / sizeof(arr[0]);
  findLargestandSecondLargest(size, arr);
  return 0;
}
