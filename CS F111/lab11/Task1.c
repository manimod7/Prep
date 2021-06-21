//TASK 1 -
#include <stdio.h>
#include <string.h>

    int main()
{
  char s[30], t[20];
  char str[40];
  puts("Enter the first string: ");
  gets(s);
  puts("Enter the string to be searched: ");
  gets(t);
  int j = 0;
  int p = -1;
  int count = 0;
  int k;
  int flag = 0;
  for (int i = 0; i < strlen(s); i++)
  {
    k = i;
    count = 0;
    for (int j = 0; j < strlen(t); j++)
    {
      if (s[k] == t[j])
      {

        count++;
        k++;
      }
      if (count == strlen(t))
      {
        p = k - strlen(t);
        flag = 1;
        break;
      }
    }
  }
  if (flag == 1)
    printf("Found at %d", p);
  else

    printf("-1");
}