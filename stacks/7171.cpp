#include<bits/stdc++.h>
using namespace std;

int main()
{
  string path = "/a/./b/../../c/";
  string res, s;
  stack<string> stk;
  stringstream ss(path);
  while (getline(ss, s, '/'))
  {
    cout<<s<<endl;
    if (s == "" || s == ".")
      continue;
    if (s == ".." && !stk.empty())
      stk.pop();
    else if (s != "..")
      stk.push(s);
  }
  while (!stk.empty())
  {
    res = "/" + stk.top() + res;
    stk.pop();
  }
  string ans = res.empty() ? "/" : res;
  cout<<ans;
  return 0;
}