//Q1.Write a program to pass entire array elements to a function by using Call by Reference parameter passing mechanism.*
#include <stdio.h>
void display(int *j, int n)
{
  int i;
  for (i = 0; i <= n - 1; i++)
  {
    printf("\n element = %d", *j);
    j++;
  }
}
int main()
{
  int marks[] = {120, 34, 65, 45};
  display(&marks[0], 4);
}