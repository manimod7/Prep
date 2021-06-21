class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int reach = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
      reach = max(reach, i + nums[i]);
      if (i >= reach && reach < n - 1)
        return false;
    }
    return true;
  }
};