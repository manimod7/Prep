class Solution
{
public:
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

  int solve(string &s, int i, int j, vector<vector<int>> &dp)
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
        int temp = solve(s, k + 1, j, dp) + 1;
        ans = min(ans, temp);
      }
    }
    return dp[i][j] = ans;
  }

  int minCut(string str)
  {

    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    solve(str, 0, n - 1, dp);
    return dp[0][n - 1];
  }
};