class Solution
{
public:
  int dp[502][502];
  int solve(vector<int> &nums, int i, int j)
  {
    if (i >= j)
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    int maxi = INT_MIN;
    for (int k = i; k < j; k++)
    {
      int tempAns = solve(nums, i, k) + solve(nums, k + 1, j) + nums[i - 1] * nums[k] * nums[j];
      maxi = max(maxi, tempAns);
    }
    return dp[i][j] = maxi;
  }
  int maxCoins(vector<int> &nums)
  {
    memset(dp, -1, sizeof(dp));
    vector<int> nums1;
    nums1.push_back(1);
    for (int i = 0; i < nums.size(); i++)
      nums1.push_back(nums[i]);
    nums1.push_back(1);
    int ans = solve(nums1, 1, nums1.size() - 1);
    return ans;
  }
};