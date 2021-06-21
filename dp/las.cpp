class Solution
{
public:
  int longestArithSeqLength(vector<int> &nums)
  {
    int n = nums.size(), cd;
    vector<unordered_map<int, int>> dp(n);
    //dp[i] is map containing common difference and lengths of the LAS ending at i with the common difference
    int res = 0;
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        cd = nums[i] - nums[j];
        if (dp[j].find(cd) != dp[j].end())
          dp[i][cd] = 1 + dp[j][cd];
        else
          dp[i][cd] = 2;
        res = max(res, dp[i][cd]);
      }
    }
    return res;
  }
};