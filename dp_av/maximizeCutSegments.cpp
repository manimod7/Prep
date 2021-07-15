//Cut a rod of given length so that there are max number of cuts

class Solution
{
public:
  //Function to find the maximum number of cuts.
  int helper(int n, int x, int y, int z, vector<int> &dp)
  {
    if (n == 0)
      return 0;
    if (dp[n] != -1)
      return dp[n];
    int a, b, c;
    a = b = c = INT_MIN;
    if (n >= x)
      a = helper(n - x, x, y, z, dp);
    if (n >= y)
      b = helper(n - y, x, y, z, dp);
    if (n >= z)
      c = helper(n - z, x, y, z, dp);
    return dp[n] = 1 + max(a, max(b, c));
  }

  int maximizeTheCuts(int n, int x, int y, int z)
  {
    //Your code here

    vector<int> dp(n + 1, -1);
    int ans = helper(n, x, y, z, dp);
    if (ans < 0)
      return 0;
    return ans;
  }
};