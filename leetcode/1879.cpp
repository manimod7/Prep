class Solution
{
public:
  int heda(int i, int j, vector<vector<int>> &dp, vector<int> &nums1, vector<int> &nums2)
  {
    if (i == nums1.size())
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    int res = INT_MAX, n = nums1.size();
    for (int k = 0; k < n; k++)
    {
      if ((j & (1 << k)) == 0)
      {
        res = min(res, (nums1[i] ^ nums2[k]) + heda(i + 1, j | (1 << k), dp, nums1, nums2));
      }
    }
    return dp[i][j] = res;
  }
  int minimumXORSum(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums1.size();
    vector<vector<int>> dp(n, vector<int>((1 << (n + 1)), -1));
    return heda(0, 0, dp, nums1, nums2);
  }
};