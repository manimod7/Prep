//* Palindrome Partitioning 4

//Recursive Approach

class Solution
{
public:
  bool isPal(string &s, int i, int j)
  {
    while (i < j)
      if (s[i++] != s[j--])
        return false;
    return true;
  }
  bool checkPartitioning(string s)
  {
    for (auto i = 2; i < s.size(); ++i)
    {
      if (isPal(s, i, s.size() - 1))
      {
        for (auto j = 1; j < i; ++j)
          if (isPal(s, j, i - 1) && isPal(s, 0, j - 1))
            return true;
      }
    }
    return false;
  }
};

//DP baazi

class Solution
{
public:
  bool checkPartitioning(string s)
  {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
      dp[i][i] = 1;
    for (int i = 0; i < n - 1; i++)
    {
      if (s[i] == s[i + 1])
        dp[i][i + 1] = 1;
      else
        dp[i][i + 1] = 0;
    }
    for (int k = 3; k <= n; k++)
    {
      for (int i = 0; i < n - k + 1; i++)
      {
        int j = k + i - 1;
        if (dp[i + 1][j - 1] == 1 && s[i] == s[j])
          dp[i][j] = 1;
        else
          dp[i][j] = 0;
      }
    }
    for (int i = 0; i < n - 2; i++)
    {
      for (int j = i + 1; j < n - 1; j++)
      {
        if (dp[0][i] && dp[i + 1][j] && dp[j + 1][n - 1])
          return true;
      }
    }
    return false;
  }
};