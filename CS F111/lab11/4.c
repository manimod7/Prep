//Q4
#include <stdio.h>
#include <string.h>
int main()
{
  char s[30], t[20];
  char *found;

  /* Entering the main string */
  puts("Enter the first string: ");
  gets(s);

  /* Entering the string whose postion or index is to be displayed */
  puts("Enter the string to be searched: ");
  gets(t);

  /* searching string t in string s */
  found = strstr(s, t);
  if (found)
    printf("second string is found in first string at %d position . \n", found - s);
  else
    printf("-1");

  return 0;
}