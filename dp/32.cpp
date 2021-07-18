class Solution
{
public:
  //dp[i] = the longest valid paranthesis ending at i
  int longestValidParentheses(string s)
  {
    int n = s.size();
    if (n == 0)
      return 0;
    int res = 0;
    vector<int> dp(n, 0);
    int startIndex = 0;
    for (int i = 1; i < n; i++)
    {
      if (s[i] == ')')
      {
        startIndex = i - dp[i - 1] - 1;
        if (startIndex >= 0 && s[startIndex] == '(')
        {
          dp[i] = 2 + dp[i - 1];
          if (startIndex > 1)
            dp[i] += dp[startIndex - 1];
        }
      }
      cout << dp[i] << endl;
      res = max(res, dp[i]);
    }
    return res;
  }
};