class Solution
{
public:
  int dp[56];
  int ans = 1;
  int solve(int k)
  {
    if (dp[k] != -1)
      return dp[k];
    int temp1 = 0, temp2 = 0, ans = 0, res = 0;
    for (int i = 1; i <= k / 2; i++)
    {
      if (i == 1)
      {
        temp1 = k - 1;
        temp2 = solve(k - 1);
      }
      else
      {
        temp1 = (k - i) * i;
        temp2 = max(i * solve(k - i), (k - i) * solve(i));
      }
      ans = max(temp1, temp2);
      res = max(res, ans);
    }
    return dp[k] = res;
  }
  int integerBreak(int n)
  {
    memset(dp, -1, sizeof(dp));

    dp[2] = 1;
    dp[3] = 2;
    return solve(n);
  }
};