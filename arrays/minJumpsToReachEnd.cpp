class Solution
{
public:
  int minJumps(int arr[], int n)
  {
    // Your code here
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (j + arr[j] >= i)
        {
          if (dp[j] != INT_MAX)
            dp[i] = min(dp[i], 1 + dp[j]);
        }
      }
    }
    return dp[n - 1] != INT_MAX ? dp[n - 1] : -1;
  }
};