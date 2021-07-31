class Solution
{
public:
  vector<vector<int>> ans;

  void solve(int start, int end, int target, vector<int> &nums, vector<int> curr)
  {

    if (target == 0)
    {
      ans.push_back(curr);
      return;
    }
    if (target < 0 || start > end)
      return;

    for (int i = start; i < nums.size(); i++)
    {
      if (nums[i] > target)
        break;
      if (i > start && nums[i] == nums[i - 1])
        continue;

      curr.push_back(nums[i]);
      solve(i + 1, end, target - nums[i], nums, curr);
      curr.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &nums, int target)
  {

    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> curr;
    solve(0, n - 1, target, nums, curr);
    return ans;
  }
};