//Task 1 : Modify the above code to implement parameter passing mechanism usingCall - by - Value.*
#include <stdio.h>
void  display(int j[], int n)
{
  for (int i = 0; i < n; i++)
    printf("Element = %d\n", j[i]);
}
int main()
{
  int marks[] = {120, 34, 65, 45};
  display(marks, 4);

  return 0;
}