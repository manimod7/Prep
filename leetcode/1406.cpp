class Solution
{
public:
  string stoneGameIII(vector<int> &stoneValue)
  {

    int n = stoneValue.size();
    vector<int> dp(n + 1, 0);
    int i = n - 1;

    while (i >= 0)
    {
      int ans = INT_MIN;
      ans = max(stoneValue[i] - dp[i + 1], ans);

      if (i + 1 < n)
        ans = max(ans, stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);

      if (i + 2 < n)
        ans = max(ans, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);

      dp[i] = ans;
      i--;
    }

    if (dp[0] > 0)
      return "Alice";
    if (dp[0] < 0)
      return "Bob";
    else
      return "Tie";
  }
};