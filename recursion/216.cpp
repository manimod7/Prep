class Solution
{
public:
  vector<vector<int>> res;

  void solve(int k, int start, int end, int target, vector<int> currSet)
  {
    if (k == 0 && target == 0)
      res.push_back(currSet);
    if (start > target)
      return;
    if (k == 0 && target != 0)
      return;
    if (target < 0)
      return;
    if (target == 0 && k != 0)
      return;
    if (start > end)
      return;

    solve(k, start + 1, end, target, currSet);

    currSet.push_back(start);
    solve(k - 1, start + 1, end, target - start, currSet);
  }
  vector<vector<int>> combinationSum3(int k, int n)
  {
    if (n > 45)
      return {};

    vector<int> currSet;
    solve(k, 1, 9, n, currSet);

    return res;
  }
};