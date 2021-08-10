class Solution
{
public:
  int smallestDivisor(vector<int> &nums, int threshold)
  {
    int left = 1, right = 1e6, mid, sum;
    while (left < right)
    {
      sum = 0;
      mid = (left + right) / 2;
      for (int i : nums)
      {
        sum += (i + mid - 1) / mid;
      }
      if (sum > threshold)
        left = mid + 1;
      else
        right = mid;
    }
    return left;
  }
};