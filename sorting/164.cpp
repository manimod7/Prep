class Solution
{
public:
  int maximumGap(vector<int> &nums)
  {
    int n = nums.size();
    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());

    if (maxVal == minVal)
      return 0;

    int range = (maxVal - minVal) / n + 1;

    vector<vector<int>> bucket(n + 1);

    for (int i = 0; i < n; i++)
    {
      int index = (nums[i] - minVal) / range;
      bucket[index].push_back(nums[i]);
    }
    int maxDiff = INT_MIN;
    int prev_val = minVal;
    for (auto b : bucket)
    {
      sort(b.begin(), b.end());

      for (auto i : b)
      {
        maxDiff = max(maxDiff, i - prev_val);
        prev_val = i;
      }
    }

    return maxDiff;
  }
};
