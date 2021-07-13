#include <bits/stdc++.h>
using namespace std;
int main(){
  
  int k =5;
  vector<int> nums {4,5,0,-2,-3,1};
  int n = nums.size();
  int sum = 0;
  int ans = 0;
  unordered_map<int, int> umap;
  umap[0] = 1;
  for (int i = 0; i < n; i++)
  {
    sum += nums[i];
    int remainder = sum % k;
    if (remainder < 0)
      remainder = remainder + k;
    if (umap.find(remainder) == umap.end())
      umap[remainder]++;
    else
    {
      ans += umap[remainder];
      umap[remainder]++;
    }
  }
  return 0;
}
