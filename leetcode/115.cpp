class Solution
{
public:
  int numDistinct(string s, string t)
  {

    int m = s.size(), n = t.size();
    if (n > m || (n == m && s != t))
      return 0;
    if (s == t)
      return 1;
    vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));

    for (int i = 0; i <= m; i++)
      dp[i][0] = 1;
    for (int i = 1; i <= m; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (s[i - 1] == t[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        else
          dp[i][j] = dp[i - 1][j];
      }
    }
    return dp[m][n];
  }
};