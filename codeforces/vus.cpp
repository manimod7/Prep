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

  int n,m,k;
  cin>>n>>m>>k;
  if(m>=n && k>=n)
    cout<<"YES";
  else
    cout<<"NO";
  return 0;
}
