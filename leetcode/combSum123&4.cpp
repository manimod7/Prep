//Combination Sum

class Solution
{
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    vector<vector<int>> res;
    sort(candidates.begin(), candidates.end());
    vector<int> v;
    helper(res, candidates, 0, v, target);
    return res;
  }

  void helper(vector<vector<int>> &res, vector<int> &cand, int start,
              vector<int> &v, int target)
  {
    if (target == 0)
      res.push_back(v);
    else if (target > 0)
    {
      for (int i = start; i < cand.size(); i++)
      {
        if (target - cand[i] < 0)
          break;
        v.push_back(cand[i]);
        helper(res, cand, i, v, target - cand[i]);
        v.pop_back();
      }
    }

    return;
  }
};

//Combination Sum 2

class Solution
{
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {
    vector<vector<int>> res;
    sort(candidates.begin(), candidates.end());
    vector<int> v;
    helper(res, candidates, 0, v, target);
    return res;
  }

  void helper(vector<vector<int>> &res, vector<int> &cand, int start,
              vector<int> &v, int target)
  {

    if (target == 0)
      res.push_back(v);
    else if (target > 0)
    {

      for (int i = start; i < cand.size(); i++)
      {
        if (i != start && cand[i] == cand[i - 1])
          continue;
        // 1 1 2 5 target =8 (1,2,5) needed only
        if (target - cand[i] < 0)
          break;
        v.push_back(cand[i]);
        helper(res, cand, i + 1, v, target - cand[i]);
        v.pop_back();
      }
    }

    return;
  }
};

//Combination Sum 3

class Solution
{
public:
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<vector<int>> res;
    vector<int> v;
    helper(res, v, k, n, 1);
    return res;
  }

  void helper(vector<vector<int>> &res, vector<int> &v, int k, int n, int start)
  {
    if (n == 0 && k == 0)
    {
      res.push_back(v);
    }
    else if (n > 0 && k > 0)
    {
      for (int i = start; i <= 9; i++)
      {
        if (n - i < 0)
          break;
        v.push_back(i);
        helper(res, v, k - 1, n - i, i + 1);
        v.pop_back();
      }
    }
  }
};

//Combination Sum IV

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
