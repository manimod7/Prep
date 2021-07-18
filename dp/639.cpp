class Solution
{
public:
  int numDecodings(string s)
  {
    int n = s.size();
    vector<long long> dp(n + 1, 0);
#define mod 1000000007;
    dp[0] = 1;
    dp[1] = 1;
    if (s[0] == '*')
      dp[1] = 9;
    if (s[0] == '0')
      return 0;

    for (int i = 2; i <= n; i++)
    {
      if (s[i - 1] >= '1' and s[i - 1] <= '9')
      {
        dp[i] = dp[i - 1];
        if (s[i - 2] == '1' or (s[i - 2] == '2' and (s[i - 1] >= '0' and s[i - 1] <= '6')))
          dp[i] += dp[i - 2];
        else if (s[i - 2] == '*')
        {
          if (s[i - 1] <= '6')
          {
            dp[i] += 2 * dp[i - 2];
          }
          else
          {
            dp[i] += dp[i - 2];
          }
        }
      }
      else if (s[i - 1] == '*')
      {
        dp[i] = 9 * dp[i - 1];
        if (s[i - 2] == '1')
          dp[i] += 9 * dp[i - 2];
        else if (s[i - 2] == '2')
          dp[i] += 6 * dp[i - 2];
        else if (s[i - 2] == '*')
        {
          dp[i] += 15 * dp[i - 2];
        }
      }
      else if (s[i - 1] == '0')
      {
        if (s[i - 2] == '1' || s[i - 2] == '2')
        {
          dp[i] = dp[i - 2];
        }
        else if (s[i - 2] == '*')
        {
          dp[i] = 2 * dp[i - 2];
        }
      }
      dp[i] = dp[i] % mod;
    }
    return dp[n] % mod;
  }
};