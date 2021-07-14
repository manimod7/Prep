class Solution
{
public:
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    int n = nums.size();
    for (int i = 0; i < n; i++)
      nums[i] = nums[i] % 2;

    int res = 0, currsum = 0;
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