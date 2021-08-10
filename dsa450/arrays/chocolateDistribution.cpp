class Solution
{
public:
  void nextPermutation(vector<int> &nums)
  {
    // Find the first number which is decreasing (from the right)
    int n = nums.size(), i, pos, j;

    if (n == 0)
      return;

    for (i = n - 2; i >= 0 && nums[i] >= nums[i + 1]; i--)
      ;

    pos = i;
    if (pos >= 0)
    {
      // Find out the first (smallest) number which is greater
      for (i = n - 1; i >= 0 && nums[i] <= nums[pos]; i--)
        ;

      // i >= 0
      swap(nums[pos], nums[i]);
    }
    reverse(nums.begin() + pos + 1, nums.end());
  }
};