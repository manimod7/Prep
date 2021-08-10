class Solution
{
public:
  void sortColors(vector<int> &a)
  {
    int n = a.size();
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
