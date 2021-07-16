class Solution
{
public:
  int dp[2002][2002];
  bool isPalindrome(int i, int j, string &s)
  {
    while (i <= j)
    {
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }

  int solve(string &s, int i, int j)
  {
    if (dp[i][j] != -1)
      return dp[i][j];
    if (i > j || isPalindrome(i, j, s))
    {
      return dp[i][j] = 0;
    }
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
      if (isPalindrome(i, k, s))
      {
        int temp = solve(s, k + 1, j) + 1;
        ans = min(ans, temp);
      }
    }
    return dp[i][j] = ans;
  }

  int minCut(string str)
  {
    memset(dp, -1, sizeof(dp));
    int n = str.size();
    solve(str, 0, n - 1);
    return dp[0][n - 1];
  }
};