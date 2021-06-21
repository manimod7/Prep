//Q3 Write a program to multiply two matrices using Two - dimensional Arrays and print the resultant matrix.*
#include <stdio.h>
void  mult_matrices(int a[][3], int[][3], int result[][3]);
void print_matrix(int a[][3]);

int main(void)
{
  int p[3][3] = {{1, 3, -4}, {1, 1, -2}, {-1, -2, 5}};
  int q[3][3] = {{8, 3, 0}, {3, 10, 2}, {0, 2, 6}};
  int r[3][3];
  mult_matrices(p, q, r);
  print_matrix(r);
}
void print_matrix(int a[][3])
{
  int i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf("%d\t", a[i][j]);
    }
    printf("\n");
  }
}
void mult_matrices(int a[][3], int b[][3], int result[][3])
{
  int i, j, k;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      result[i][j] = 0;
      for (k = 0; k < 3; k++)
      {

        result[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}