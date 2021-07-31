class Solution
{
public:
  unordered_map<int, int> dp;

  int combinationSum4(vector<int> &nums, int target)
  {
    sort(nums.begin(), nums.end());
    // dp[0]=1;
    return helper(nums, target);
  }

  int helper(vector<int> &nums, int target)
  {
    if (dp.count(target))
      return dp[target];
    int ans = 0;
    if (target == 0)
      return 1;
    else if (target > 0)
    {
      for (int i = 0; i < nums.size(); i++)
      {
        if (target - nums[i] < 0)
          break;
        int cnt = helper(nums, target - nums[i]);
        ans += cnt;
      }
      return dp[target] = ans;
    }

    return 0;
  }
};