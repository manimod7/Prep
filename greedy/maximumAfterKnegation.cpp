class Solution
{
public:
  long long int maximizeSum(long long int a[], int n, int k)
  {
    // Your code goes here
    sort(a, a + n);
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
      if (a[i] < 0 && k > 0)
      {
        a[i] = -a[i];
        k--;
      }
    }
    long long int x = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      sum += a[i];
      x = min(x, a[i]);
    }
    if (k & 1)
      sum = sum - 2 * x;
    return sum;
  }
};