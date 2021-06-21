#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n];
  int b[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  int mx =INT_MIN,mn=INT_MAX;
  for(int i=0;i<n;i++){
    mx=max(mx,a[i]);
    mn=min(mn,b[i]);
  }
  int ans =0;
  if(mn<mx)
    ans =0;
  else
    ans = mn-mx+1;
    cout<<ans;
  return 0;
}
