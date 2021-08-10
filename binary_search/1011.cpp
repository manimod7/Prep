class Solution
{
public:
  int shipWithinDays(vector<int> &weights, int D)
  {
    int left = 0, right = 1e6;
    for (int w : weights)
      left = max(left, w);
    while (left < right)
    {
      int mid = (left + right) / 2, need = 1, cur = 0;
      for (int i = 0; i < weights.size() && need <= D; i++)
      {
        if (cur + weights[i] > mid)
          cur = 0, need++;
        cur += weights[i];
      }
      if (need > D)
        left = mid + 1;
      else
        right = mid;
    }
    return left;
  }
};