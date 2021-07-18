class Solution
{
public:
  int dp[60];
  int solve(int n)
  {
    if (dp[n] != -1)
      return dp[n];
    int res = 0, ans = 0;
    int temp1, temp2, temp3, temp4;
    for (int i = 1; i <= n / 2; i++)
    {
      temp1 = i * solve(n - i);
      temp2 = i * (n - i);
      temp3 = solve(i) * (n - i);
      temp4 = solve(i) * solve(n - i);
      res = max(temp1, max(temp2, max(temp3, temp4)));
      ans = max(ans, res);
    }
    return dp[n] = ans;
  }
  int integerBreak(int n)
  {
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    return solve(n);
  }
};