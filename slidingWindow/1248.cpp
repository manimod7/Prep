#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> nums{1,1,0,1,1,0,0,1,0,1,1,0,0,0,1};
  int k =3;
  int n =nums.size();
  for(int i=0;i<n;i++)
      nums[i] = nums[i]%2;
        
  int res=0 ,currsum=0;
  unordered_map<int, int> map;
  map[0]=1;
  for(int i=0;i<n;i++){
      currsum+=nums[i];
      res+=map[currsum-k];
      map[currsum]++;
  }
  return 0;
}
