class Solution
{
public:
  int solve(int e, int f, vector<vector<int>> &dp)
  {
    if (e == 1)
      return f;
    if (f == 0 || f == 1)
      return f;

    if (dp[e][f] != -1)
      return dp[e][f];

    int ans = INT_MAX;

    int low = 1, high = f;
    while (low <= high)
    {
      int left, right;
      int mid = (low + high) / 2;

      if (dp[e - 1][mid - 1] != -1)
        left = dp[e - 1][mid - 1];
      else
        left = solve(e - 1, mid - 1, dp);

      if (dp[e][f - mid] != -1)
        right = dp[e][f - mid];
      else
        right = solve(e, f - mid, dp);

      int temp = max(left, right) + 1;
      ans = min(ans, temp);

      if (left < right) //since right is more than left and we need more in wrost case
        low = mid + 1;  // so l=mid+1 to gain more temp for worst case: upward
      else              //left > right so we will go downward
        high = mid - 1;
    }
    return dp[e][f] = ans;
  }
  int superEggDrop(int e, int f)
  {

    vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));
    return solve(e, f, dp);
  }
};