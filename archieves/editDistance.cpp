#include<bits/stdc++.h>
using namespace std;

int solve(string s1, string s2, int i, int j){
  if(i==s1.size() && j==s2.size())
    return 0;
  if(j==s2.size())
    return s1.size() -i;
  if(i==s1.size())
    return s2.size() - j;
  if(s1[i]==s2[j])
    return solve(s1,s2,i+1,j+1);
  int ans1 = min(solve(s1,s2,i+1,j+1), solve(s1,s2,i,j+1));
  int ans2 = min(ans1, solve(s1,s2,i+1,j));
  return ans2+1;
  
}
int main()
{
  string s1 ="abcd", s2 ="cdfg";
  int ans = solve(s1,s2,0,0);
  cout<<ans;
  return 0;
}