#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int main(){
  vector<bool> base2 {1,0,1,1};
__int128 n=0, p=1;
  for(int i=0;i<base2.size();i++){
    if(base2[i]==1)
      n+=p;
      p=p*2;
  }
  vector<int> ans;
  while(n!=0){
    ans.push_back(n%6);
    n/=6;
  }
  reverse(ans.begin(), ans.end());
  for(int i=0;i<ans.size();i++){
    cout<<ans[i];
  }


  return 0;
}
