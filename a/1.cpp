#include <bits/stdc++.h>

using namespace std;
unordered_map<int, __int128> mp;
int fact(int i){
  if(i==0||i==1)
    return 1 ;
  if(mp[i])
    return mp[i];
  mp[i] = i* fact(i-1);
  return mp[i];
}
int main(){
  int n;
  cin>>n;
  int ans =fact(n);
  cout<<ans<<endl;
  
}