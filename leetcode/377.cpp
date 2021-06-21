#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void solve(vector<int> &nums, int start, int end, int target, vector<int> currSet)
{

  if (start <= end && target == 0)
  {
    res.push_back(currSet);
    return;
  }
  if (start > end || target < 0 || nums[start] > target)
    return;


  solve(nums, start + 1, end, target, currSet);
  currSet.push_back(nums[start]);
  solve(nums, start, end, target - nums[start], currSet);
}

int main(){

  vector<int> nums {1,2,3};
  int target = 4;
  sort(nums.begin(), nums.end());
  vector<int> currSet;
  solve(nums, 0, nums.size() - 1, target, currSet);

  return 0;
}
