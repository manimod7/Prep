class Solution
{
public:
  int dp[1003][1003];
  int sum[1003];
  int solve(int i, int j, vector<int> &stones)
  {
    if (i > j)
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    return dp[i][j] = max(sum[j + 1] - sum[i + 1] - solve(i + 1, j, stones), sum[j] - sum[i] - solve(i, j - 1, stones));
  }
  int stoneGameVII(vector<int> &stones)
  {
    memset(sum, 0, sizeof(sum));
    memset(dp, -1, sizeof(dp));
    int n = stones.size();
    for (int i = 0; i < n; i++)
    {
      sum[i + 1] = sum[i] + stones[i];
    }
    return solve(0, n - 1, stones);
  }
};