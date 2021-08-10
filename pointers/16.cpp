class Solution
{
public:
  int threeSumClosest(vector<int> &nums, int target)
  {
    int res = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n - 2; i++)
    {
      int l = i + 1, r = n - 1;
      while (l < r)
      {
        int currSum = nums[i] + nums[l] + nums[r];
        if (currSum > target)
          r--;
        else
          l++;

        if (abs(currSum - target) < abs(res - target))
          res = currSum;
      }
    }
    return res;
  }
};

//-4  -1  1  2  3  5  7