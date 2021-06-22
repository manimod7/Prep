#include <bits/stdc++.h>
using namespace std;
int main(){
  map<int, int> mp;
  mp[1]=1;
  mp[3]=1;
  mp[7]=1;
  mp[32]=1;
  mp[51]=1;
  mp[178]=1;
  for(auto itr :mp){
    cout<<itr.first<<endl;
  }
  return 0;
}
