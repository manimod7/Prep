class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    int n = nums.size(), lo, mid, hi;
    if (n == 0)
      return {-1, -1};
    vector<int> res;
    lo = 0, hi = n - 1;
    while (lo < hi)
    {
      mid = (lo + hi) / 2;
      if (nums[mid] >= target)
      {
        hi = mid;
      }
      else
      {
        lo = mid + 1;
      }
    }

    if (nums[lo] != target)
    {
      return {-1, -1};
    }
    res.push_back(lo);

    lo = 0, hi = n - 1;
    while (lo < hi)
    {
      mid = (lo + hi + 1) / 2;
      if (nums[mid] > target)
        hi = mid - 1;
      else
      {
        lo = mid;
      }
    }
    res.push_back(lo);
    return res;
  }
};