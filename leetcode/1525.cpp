#include <bits/stdc++.h>
using namespace std;
int main(){
  string s ="aaaaa";
  int n = s.size();
  int cnt = 0;
  set<char> s1;
  set<char> s2;
  for (int i = 1; i < n - 1; i++)
  {
    for (int j = 0; j < i; j++)
      s1.insert(s[j]);
    for (int k = i; k < n; k++)
      s2.insert(s[k]);
    if (s1.size() == s2.size())
      cnt++;
    s1.clear();
    s2.clear();
  }
  return 0;
}
