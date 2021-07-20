class Solution
{
public:
  int dp[50001];
  int solve(vector<int> stoneValue, int startIndex)
  {
    int n = stoneValue.size();

    if (startIndex >= n)
      return dp[startIndex] = 0;
    if (dp[startIndex] != -1)
      return dp[startIndex];
    int ans = INT_MIN;

    ans = max(ans, stoneValue[startIndex] - solve(stoneValue, startIndex + 1));

    if (startIndex + 1 < n)
      ans = max(ans, stoneValue[startIndex] +
                         stoneValue[startIndex + 1] -
                         solve(stoneValue, startIndex + 2));

    if (startIndex + 2 < n)
      ans = max(ans,  stoneValue[startIndex] +
                      stoneValue[startIndex + 1] +
                      stoneValue[startIndex + 2] -
                      solve(stoneValue, startIndex + 3));
    return dp[startIndex] = ans;
  }

  string stoneGameIII(vector<int> &stoneValue)
  {
    memset(dp, -1, sizeof(dp));
    int ans = solve(stoneValue, 0);
    if (ans > 0)
      return "Alice";
    if (ans < 0)
      return "Bob";
    else
      return "Tie";
  }
};