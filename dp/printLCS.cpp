#include<bits/stdc++.h>
using namespace std;

int main(){
  string s1 ="abcdef";
  string s2 = "abacdf";
  int x =s1.size(),y=s2.size();
  vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
  for (int i = 1; i <= x; i++)
  {
    for (int j = 1; j <= y; j++)
    {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  string res ="";
  int i=x,j=y;
  while(i!=0||j!=0){
    if(s1[i-1]==s2[j-1])
      {
        res+=s1[i-1];
        i--;
        j--;
      }
    else{
      if(dp[i-1][j]>dp[i][j-1]){
        i--;
      }
      if(dp[i][j-1]>dp[i-1][j]){
        j--;
      }
    }
  }
  reverse(res.begin(),res.end());
  cout<<res<<endl;
  return 0;
}