class Solution
{
public:
  //Bottom Up Approach
  int lengthOfLIS(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return 1;
    int res = 1;
    vector<int> lis(n, 1);
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (nums[i] > nums[j])
          lis[i] = max(lis[i], 1 + lis[j]);
      }
      res = max(res, lis[i]);
    }
    return res;
  }
};
//   10  9  2  5  3  7  101  18
//    1  1  1  1  1  1    1   1