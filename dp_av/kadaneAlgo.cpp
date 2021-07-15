#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> nums {-2, -3, 4, -1, -2, 1, 5, -3};

  int n =nums.size();
  int maxEndingHere=0, maxSoFar =INT_MIN;
  for(int i=0;i<n;i++){
    maxEndingHere +=nums[i];
    if(maxEndingHere<nums[i])
      maxEndingHere =nums[i];
    if(maxSoFar<maxEndingHere)
      maxSoFar = maxEndingHere;
  }
  cout<<maxSoFar;
  return 0;
}
