class Solution
{
public:
  int wiggleMaxLength(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> positive(n, 1), negative(n, 1);

    int ans = 1;
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (nums[i] > nums[j])
        {
          positive[i] = max(positive[i], negative[j] + 1);
        }
        if (nums[i] < nums[j])
        {
          negative[i] = max(negative[i], positive[j] + 1);
        }
      }
      ans = max(ans, max(positive[i], negative[i]));
    }
    return ans;
  }
};