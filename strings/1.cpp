#include <bits/stdc++.h>
using namespace std;
int main(){
  string s ="abcd";
  for(int i=0;i<s.size();i++)
    if(s[i]>=97 &&s[i]<=122)
      s[i]=s[i]-32;
  cout<<s<<endl;
  // string b = s[0] -32;
  cout<<b;
  return 0;
}
