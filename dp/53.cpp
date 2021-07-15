class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> dp(n + 1, 0);
    dp[0] = nums[0];
    cout << dp[0] << endl;
    int res = nums[0];
    for (int i = 1; i < n; i++)
    {
      dp[i] = max(nums[i], dp[i - 1] + nums[i]);
      cout << dp[i] << endl;
      res = max(res, dp[i]);
    }
    return res;
  }
};