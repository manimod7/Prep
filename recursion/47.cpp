class Solution
{
public:
  vector<vector<int>> ans;
  void recurse(unordered_map<int, int> &mp, int n, vector<int> &op)
  {

    if (op.size() == n)
    {
      ans.push_back(op);
      return;
    }

    for (auto j = mp.begin(); j != mp.end(); j++)
    {
      if (j->second == 0)
        continue;

      j->second--;
      op.push_back(j->first);
      recurse(mp, n, op);
      op.pop_back();
      j->second++;
    }
  }

  vector<vector<int>> permuteUnique(vector<int> &nums)
  {
    unordered_map<int, int> mp;
    int i;
    for (i = 0; i < nums.size(); i++)
    {
      mp[nums[i]]++;
    }
    int n = nums.size();
    vector<int> op;
    recurse(mp, n, op);
    return ans;
  }
};