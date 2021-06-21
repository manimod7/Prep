//Q .2 Write a program to search an element in an Array using Binary search technique.*
#include <stdio.h>
#define MAX_SIZE 5
    void
    binary_search(int fn_arr[], int element)
{
  int f = 0, r = MAX_SIZE, mid;
  while (f <= r)
  {
    mid = (f + r) / 2;
    if (fn_arr[mid] == element)
    {
      printf("\n Search Element %d Found at the Position %d\n", element, mid + 1);
      break;
    }
    else if (fn_arr[mid] < element)
    {
      f = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
    if (f > r)
    {
      printf("\n Search Element %d NOT FOUND", element);
    }
  }
}

int main()
{
  int arr_search[MAX_SIZE], i, element;
  printf("Simple Binary Search using Arrays\n");
  printf("\n Enter %d Element in Ascending Order : \n", MAX_SIZE);
  for (i = 0; i < MAX_SIZE; i++)
  {
    scanf("%d", &arr_search[i]);
  }
  printf("\n Enter Element to search :");
  scanf("%d", &element);
  binary_search(arr_search, element);

  return 0;
}