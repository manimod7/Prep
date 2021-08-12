#include<bits/stdc++.h>
using namespace std;

int main()
{
  int r = 0;
  int n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 2; j < n; j++)
    {
      if (a[i] + a[i + 1] > a[j])
      {
        if (j - i + 1 > r)
        {
          r = j - i + 1;
        }
      }
    }
  }
  return r;
  return 0;
}