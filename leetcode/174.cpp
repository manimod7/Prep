class Solution
{
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon)
  {
    int m = dungeon.size();
    int n = dungeon[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    //If a[m-1][n-1] is greater than 0 than min health required to be there is 1, else you would need 1- s[m-1][n-1] to be there at least
    dp[m - 1][n - 1] = dungeon[m - 1][n - 1] > 0 ? 1 : -dungeon[m - 1][n - 1] + 1;

    //if last row, you can oly go to the right
    for (int j = n - 2; j >= 0; j--)
      dp[m - 1][j] = max(1, dp[m - 1][j + 1] - dungeon[m - 1][j]);

    //If in last coloumn, you can only go down
    for (int i = m - 2; i >= 0; i--)
      dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);

    //Rest all cases

    for (int i = m - 2; i >= 0; i--)
    {
      for (int j = n - 2; j >= 0; j--)
      {
        dp[i][j] = max(1, min(dp[i + 1][j] - dungeon[i][j], dp[i][j + 1] - dungeon[i][j]));
      }
    }
    return dp[0][0];
  }
};