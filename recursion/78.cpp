class Solution
{
public:
  int n;
  vector<vector<int>> solve(vector<int> &nums, int start)
  {
    if (start == n - 1)
      return {{}, {nums[n - 1]}};

    vector<vector<int>> s1 = solve(nums, start + 1);
    vector<vector<int>> res = s1;
    int len = s1.size();
    for (int i = 0; i < len; i++)
    {
      vector<int> t = s1[i];
      t.push_back(nums[start]);
      res.push_back(t);
    }
    return res;
  }
  vector<vector<int>> subsets(vector<int> &nums)
  {
    n = nums.size();
    vector<vector<int>> res = solve(nums, 0);
    return res;
  }
};