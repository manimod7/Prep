class Solution
{
public:
  int minEatingSpeed(vector<int> &piles, int h)
  {
    if (h < piles.size())
      return 0;
    int lo = 1, hi = 1e9, m = 0, sum = 0;
    while (lo < hi)
    {
      sum = 0;
      m = (lo + hi) / 2;
      for (auto pile : piles)
      {
        sum += (pile + m - 1) / m;
      }
      if (sum > h)
        lo = m + 1;
      else
        hi = m;
    }
    return lo;
  }
};