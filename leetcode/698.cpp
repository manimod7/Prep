class Solution
{
public:
  bool canPart(int start, vector<int> &nums, vector<bool> &visit, int curr, int target, int k)
  {
    if (k == 1)
      return true;
    if (curr == target)
    {
      return canPart(0, nums, visit, 0, target, k - 1);
    }
    for (int i = start; i < nums.size(); i++)
    {
      if (!visit[i])
      {
        visit[i] = true;
        if (canPart(i + 1, nums, visit, curr + nums[i], target, k))
        {
          return true;
        }
        visit[i] = false;
      }
    }
    return false;
  }
  bool canPartitionKSubsets(vector<int> &nums, int k)
  {
    if (nums.size() < k)
      return false;
    if (k == 1)
      return true;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
      sum += nums[i];
    if (sum % k != 0)
      return false;

    int s = sum / k;
    vector<bool> visit(nums.size(), false);
    return canPart(0, nums, visit, 0, s, k);
  }
};