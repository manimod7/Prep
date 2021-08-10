class Solution
{
public:
  int peakIndexInMountainArray(vector<int> &arr)
  {
    int n = arr.size(), lo, mid, hi;
    lo = 0, hi = n - 1;
    while (lo < hi)
    {
      mid = (lo + hi + 1) / 2;
      if (arr[mid] > arr[mid - 1])
        lo = mid;
      else
        hi = mid - 1;
    }
    return lo;
  }
};