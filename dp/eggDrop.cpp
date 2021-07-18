class Solution
{
public:
  int dp[202][202];

  int solve(int e, int f)
  {
    if (e == 1 || f == 1 || f == 0)
      return dp[e][f] = f;
    if (dp[e][f] != -1)
      return dp[e][f];
    int ans = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
      int temp = 1 + max(solve(e - 1, k - 1), solve(e, f - k)); //Taking the worse case scenario
      ans = min(ans, temp); //minimising the worst case scenarios
    }
    return dp[e][f] = ans;
  }
  //Function to find minimum number of attempts needed in
  //order to find the critical floor.
  int eggDrop(int n, int k)
  {
    // your code here
    memset(dp, -1, sizeof(dp));
    solve(n, k);
    return dp[n][k];
  }
};

