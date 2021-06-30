#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> nums {0,2,1,-3};
  int target =1;
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
  return 0;
}
