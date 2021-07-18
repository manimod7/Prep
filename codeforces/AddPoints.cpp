#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n;
  cin>>n;
  vector<int> nums(n);
  int minDiff = INT_MAX;
  for(int i=0;i<n;i++){
    cin>>nums[i];
  }
  int ans = 0;
  sort(nums.begin(), nums.end());
  for(int i=1;i<n;i++){
    minDiff =min(minDiff, nums[i]- nums[i-1]);
  }
  for(int i=1;i<n;i++){
    if(nums[i]-nums[i-1]==minDiff)
      continue;
    else
    ans+=(nums[i]-nums[i-1])/minDiff;
  }
  if(ans==0)
    cout<<0;
  else
    cout<<ans-1;
  return 0;
}
