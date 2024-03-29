class Solution
{
public:
  int distinctSubseqII(string s)
  {
    int mod = 1e9 + 7;
    unordered_map<char, int> mp; //save character and its first index
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
      dp[i] = (2 * dp[i - 1]) % mod;
      char ch = s[i - 1];
      if (mp.find(ch) != mp.end())
      {
        int j = mp[ch];
        dp[i] = dp[i] - dp[j - 1];
      }
      if (dp[i] < 0)
        dp[i] += mod;
      mp[ch] = i;
    }
    return dp[n] - 1;
  }
};