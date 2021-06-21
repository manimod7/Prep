#include<bits/stdc++.h>
using namespace std;
int main(){

  string S2 = "aggtab", S1 = "manish";
  int n =S1.size(), m=S2.size();
  int res = 0;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (S1[i - 1] == S2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = 0;
      res = max(res, dp[i][j]);
    }
  }
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;

  }
  return 0;
}