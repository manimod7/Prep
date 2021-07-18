class Solution
{
public:
  int dp[3][10001];

  int solve(int e, int f)
  {
    if (e == 1 || f == 1 || f == 0)
      return dp[e][f] = f;
    if (dp[e][f] != -1)
      return dp[e][f];
    int ans = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
      int temp = 1 + max(solve(e - 1, k - 1), solve(e, f - k));
      ans = min(ans, temp);
    }
    return dp[e][f] = ans;
  }
  int twoEggDrop(int n)
  {
    int f = n;
    int e = 2;
    //vector<vector<int>> dp(e+1, vector<int> (f+1, -1));
    memset(dp, -1, sizeof(dp));
    return solve(e, f);
  }
};