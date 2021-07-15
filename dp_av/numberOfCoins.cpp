//find min coins to make a denomination
class Solution
{
public:
  int minCoins(int coins[], int M, int V)
  {
    // Your code goes here
    vector<vector<int>> dp(M + 1, vector<int>(V + 1, 0));
    for (int i = 0; i <= V; i++)
      dp[0][i] = INT_MAX - 1;
    for (int i = 1; i <= M; i++)
    {
      for (int j = 1; j <= V; j++)
      {
        if (coins[i - 1] <= j)
          dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
    return dp[M][V] == INT_MAX - 1 ? -1 : dp[M][V];
  }
};