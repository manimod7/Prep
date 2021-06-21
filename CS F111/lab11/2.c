//Q2

#include <stdio.h>
#include <string.h>

enum Boolean
{
  false,
  true
};
enum Boolean isPalindrome(char string[])
{
  int left, right, len = strlen(string);
  enum Boolean matched = true;
  if (len == 0)
    return 0;
  left = 0;
  right = len - 1;
  /* compare the first and last letter , second and  second last & so on */
  while (left < right && matched)
  {
    if (string[left] != string[right])
      matched = false;
    else
    {
      left++;
      right--;
    }
  }
  return matched;
}

int main()
{
  char string[40];
  printf("Enter a string\n");
  scanf("%s", string);
  if (isPalindrome(string))
    printf("The given string %s is a palindrome\n", string);
  else
    printf("the given string %s is not a palindrome\n", string);

  return 0;
}