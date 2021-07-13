class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    int n = nums.size(), res = 0, currsum = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    for (int i = 0; i < n; i++)
    {
      currsum += nums[i];
      res += map[currsum - k];
      map[currsum]++;
    }
    return res;
  }
};