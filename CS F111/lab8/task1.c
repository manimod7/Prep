#include <stdio.h>
#include <math.h>

long long convert(int n);

int main()
{
  int n, temp;
  long int rem, q, dn = 0, j, i;
  char s;
  printf("Enter a decimal number: ");
  scanf("%d", &n);
  printf("%d in hexadecimal is: ", n);
  i = n;
  while (i > 0)
  {
    temp = i % 16;
    if (temp < 10)
      temp = temp + 48;
    else
      temp = temp + 55;
    dn = dn * 100 + temp;
    i = i / 16;
  }
  for (j = dn; j > 0; j = j / 100)
  {
    s = j % 100;
    printf("%c", s);
  }
}