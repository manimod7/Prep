class Solution
{
public:
  bool canPartition(vector<int> &nums)
  {
    bool ans = false;
    int sum = 0;
    int N = nums.size();
    for (int i = 0; i < N; i++)
      sum += nums[i];
    if (sum % 2 != 0)
      return false; //if sum is odd then it can't be divisible into 2 equal parts

    else
    { //if sum is even then we have to only find the one part other one automatically equal to the first one

      sum = sum / 2; //if the array had negative numbers than we cant do sum=sum/2
      //then we will calculate for sum and then return dp[N][sum/2]

      vector<vector<bool>> dp(N + 1, vector<bool>(sum + 1, false));
      for (int i = 0; i <= N; i++)
      {
        dp[i][0] = true;
      }
      for (int i = 1; i <= N; i++)
      {
        for (int j = 1; j <= sum; j++)
        {
          if (nums[i - 1] <= j)
            dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
          else
            dp[i][j] = dp[i - 1][j];
        }
      }
      ans = dp[N][sum];
      return ans;
    }
  }
};