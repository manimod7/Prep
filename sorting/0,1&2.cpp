class Solution
{
public:
  void sort012(int a[], int n)
  {
    // coode here
    int l = 0, m = 0, h = n - 1;
    while (m <= h)
    {
      if (a[m] == 0)
      {
        swap(a[m], a[l]);
        l++;
        m++;
      }
      else if (a[m] == 1)
        m++;
      else if (a[m] == 2)
      {
        swap(a[m], a[h]);
        h--;
      }
    }
  }
};