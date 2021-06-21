class Solution
{
public:
  int findTargetSumWays(vector<int> &nums, int target)
  {

    int n = nums.size(), sum = 0;
    for (int i = 0; i < n; i++)
      sum += nums[i];
    cout << sum;
    if (target > sum || target < -sum || (sum + target) % 2 == 1)
      return 0;

    int s1 = (sum + target) / 2;
    cout << endl
         << s1;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    dp[0][0] = 1;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
      dp[i][0] = dp[i - 1][0];
      if (nums[i - 1] == 0) //intializing base condition for zero
        dp[i][0] *= 2;
    }

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= sum; j++)
      {
        if (nums[i - 1] <= j)
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
    return dp[n][s1];
  }
};