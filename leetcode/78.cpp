#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> nums{1,2,3};
  vector<vector<int>> res{{}};
  for (int i = 0; i < nums.size(); i++)
  {
    int k =res.size();
    for (int j=0;j<k;j++)
    {
      vector<int> temp =res[j];
      temp.push_back(nums[i]);
      res.push_back(temp);
      cout<<"1";
    }
  }
  return 0;
}
