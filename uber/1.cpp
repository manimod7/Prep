#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;
int res = INT_MAX;

void solve(vector<int> p, int h, int start, int end,  int sum, vector<vector<int>> dp){
  if(start>end)
    return;
  if(start==end && h>1)
    return;
  if(dp[start][h]!=-1)
  {
    
    return;
  }
  if(h==0)
  {
      int maxi=0;
      for (int i = start; i <= end; i++)
      {
        maxi=max(maxi,p[i]);
      }
      res =min(res,sum+maxi);
      return;
  }
  int part=p[start];
  for(int i=start;i<=end;i++){
    part =max(part,p[i]);
    solve(p, h-1, i+1,end, sum+part, dp);
  }
}
int main(){


vector<int>p{3,1,1,1,8};
int h =3;
vector<vector<int>> dp(p.size() + 1, vector<int>(h + 1, -1));
if(h> p.size())
  cout<<"-1";
else{
  solve(p, h - 1, 0, p.size() - 1, 0, dp);
  cout << res;
}

  return 0;
}
