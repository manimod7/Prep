class Solution
{
public:
  double dp[102][102][102];
  double sum[102][102];
  vector<int> num;
  double solve(int i, int j, int k)
  {
    int n = num.size();
    if (i >= n || j >= n)
      return 0;
    if (i > j)
      return 0;
    if (k == 1)
      return dp[i][j][k] = (double)sum[i][j] / (j - i + 1);
    if (i == j)
      return dp[i][j][k] = sum[i][j];
    if (dp[i][j][k] != -1)
      return dp[i][j][k];

    double res = INT_MIN;
    for (int x = i; x < j; x++)
    {
      double temp = solve(i, x, k - 1) + ((sum[x + 1][j]) / (j - x));
      res = max(temp, res);
      //cout<<0;
    }
    return dp[i][j][k] = res;
  }
  double largestSumOfAverages(vector<int> &nums, int k)
  {
    int n = nums.size();
    //memset(sum,0.00,sizeof(sum));
    num = nums;
    for (int i = 0; i < n + 1; i++)
    {
      for (int j = 0; j < n + 1; j++)
      {
        sum[i][j] = 0.00;
        for (int x = 0; x < k + 2; x++)
          dp[i][j][x] = -1;
      }
    }
    //memset(dp,-1.00,sizeof(dp));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == j)
          sum[i][j] = nums[i];
        else if (i > j)
          sum[i][j] = 0;
        else
          sum[i][j] = sum[i][j - 1] + nums[j];
      }
    }
    double ans = solve(0, n - 1, k);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    return ans;
  }
};
