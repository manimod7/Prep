#include <bits/stdc++.h>
using namespace std;
int main(){
  string s = "abcde";
  int n = s.size();
  vector<string> res;
  res.push_back("");
  for (int i = 0; i < n; i++)
  {
    int x =res.size();
    for (int j = 0; j < x; j++)
    {
      string temp = res[j];
      temp += s[i];
      res.push_back(temp);
    }
  }
  return 0;
}
