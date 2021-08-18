#include<bits/stdc++.h>
using namespace std;
#define mod 1000000009
int main()
{
  int n;
  vector<int> dp1(n,0), dp0(n,0);
  dp1[0] = 3;
  dp0[0] = 2;
  dp1[1] = 4;
  dp0[0] = 3;

  for(int i=2;i<n;i++){
    dp1[i] =(dp1[i-1]+ 3*dp0[i-2])%mod;
    dp0[i] = (2*dp0[i-1]+2*dp1[i-2])%mod;
  }
  return 0;
}