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
  int W;
  cin>>W;
  if(W%2==0 && W>=4)
    cout<<"YES";
  else
  cout<<"NO";

  return 0;
}
