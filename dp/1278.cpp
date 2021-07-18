//* Palindrome Partitioning 3

class Solution
{
public:
  int dp[101][101];
  int toPal(string &s, int i, int j)
  {
    int ans = 0;
    while (i < j)
    {
      ans += (s[i] != s[j]);
      i++, j--;
    }
    return ans;
  }

  int help(string s, int pos, int k)
  {
    int n = s.size();
    if (k == 1)
      return toPal(s, pos, n - 1);
    if (pos == n)
      return 0;
    if (dp[pos][k] != -1)
      return dp[pos][k];
    int ans = INT_MAX; //  don't partition here
    for (int i = pos; i < n; i++)
    {
      //  partition from s[pos]s[pos+1]...s[i]
      int cur = toPal(s, pos, i);
      ans = min(ans, cur + help(s, i + 1, k - 1));
    }

    return dp[pos][k] = ans;
    
  }

  int palindromePartition(string s, int k)
  {
    memset(dp, -1, sizeof(dp));
    int n = s.size();
    return help(s, 0, k);
  }
};