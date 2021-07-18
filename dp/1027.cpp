class Solution
{
public:
  int longestArithSeqLength(vector<int> &nums)
  {
    int n = nums.size(), cd;
    vector<unordered_map<int, int>> dp(n);
    
    //* At any point i, dp[i] is the collection all of maps where last number in LAS is nums[i]
    //*dp[i][cd] is the length of LAS with common difference = cd and the last number = nums[i]
    int res = 0;
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        cd = nums[i] - nums[j];
        if (dp[j].find(cd) != dp[j].end())
          dp[i][cd] = max(dp[i][cd], 1 + dp[j][cd]);
        else
          dp[i][cd] = 2;
        res = max(res, dp[i][cd]);
      }
    }
    return res;
  }
};