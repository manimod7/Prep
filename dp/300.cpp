// *Longest Increasing Subsequence
class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    //dp[i] is the longest increasing subsequence at i
    int n = nums.size();
    int res = 1;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (nums[i] > nums[j])
          dp[i] = max(dp[i], 1 + dp[j]);
      }
      res = max(res, dp[i]);
    }
    return res;
  }
};