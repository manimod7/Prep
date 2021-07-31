class Solution
{
public:
  vector<vector<int>> res;
  void solve(vector<bool> &used, int n, vector<int> curr, vector<int> &nums)
  {
    if (curr.size() == n)
    {
      res.push_back(curr);
      return;
    }
    for (int i = 0; i < n; i++)
    {
      if (!used[i])
      {
        used[i] = true;
        curr.push_back(nums[i]);
        solve(used, n, curr, nums);
        used[i] = false;
        curr.pop_back();
      }
    }
  }
  vector<vector<int>> permute(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> curr;
    vector<bool> used(n, false);
    solve(used, n, curr, nums);
    return res;
  }
};