class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> dp(n + 1, 0);
    dp[0] = nums[0];
    cout << dp[0] << endl;
    int res = nums[0];
    for (int i = 1; i < n; i++)
    {
      dp[i] = max(nums[i], dp[i - 1] + nums[i]);
      cout << dp[i] << endl;
      res = max(res, dp[i]);
    }
    return res;
  }
};

//* By Kadane Algorithm
class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int msf = INT_MIN, meh = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      meh += nums[i];
      if (nums[i] > meh)
        meh = nums[i];
      msf = max(msf, meh);
    }
    return msf;
  }
};