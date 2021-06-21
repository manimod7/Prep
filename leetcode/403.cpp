class Solution
{
public:
  int finish;
  unordered_set<int> st;
  map<pair<int, int>, bool> dp;
  bool solve(int start, int jumpSize)
  {
    if (dp.find({start, jumpSize}) != dp.end())
      return dp[{start, jumpSize}];
    if (start == finish)
      return dp[{start, jumpSize}] = true;
    if (jumpSize <= 0)
      return false;
    if (st.find(start) == st.end())
      return dp[{start, jumpSize}] = false;
    int newIndex = start + jumpSize;
    return dp[{start, jumpSize}] = solve(newIndex, jumpSize - 1) || solve(newIndex, jumpSize) || solve(newIndex, jumpSize + 1);
  }
  bool canCross(vector<int> &stones)
  {
    int n = stones.size();
    finish = stones[n - 1];
    for (int i = 0; i < n; i++)
    {
      st.insert(stones[i]);
    }
    return solve(0, 1);
  }
};