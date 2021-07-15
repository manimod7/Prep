#define m 1000000007
class Solution
{
public:
  int numSubseq(vector<int> &nums, int target)
  {
    vector<int> powi(nums.size() + 1, 0);
    powi[0] = 1;
    for (int i = 1; i <= nums.size(); i++)
    {
      powi[i] = (2 * powi[i - 1]) % m;
    }
    sort(nums.begin(), nums.end());
    int start = 0;
    int end = nums.size() - 1;
    long ans = 0;
    while (start <= end)
    {
      if (nums[start] + nums[end] <= target)
      {
        //    ans += pow(2,end-start); // this pow  exceed limits
        ans = (ans % m + powi[end - start] % m) % m;
        start++;
      }
      else
      {
        end--;
      }
    }
    return ans;
  }
};