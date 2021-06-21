class Solution
{

public:
  int minDiffernce(int arr[], int n)
  {
    // Your code goes here
    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += arr[i];
    bool dp[n + 1][sum + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++)
      dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= sum; j++)
      {
        if (arr[i - 1] <= j)
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
    int minDiff = INT_MAX;
    for (int j = 0; j <= sum; j++)
    {
      if (dp[n][j] == true)
        minDiff = min(minDiff, abs(sum - 2 * j));
    }
    return minDiff;
  }
};