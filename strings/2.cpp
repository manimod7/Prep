#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<char> chars {'a','a','b','b','c','c','c'};
  string a;
  int n = chars.size();
  int j=0;
  for (int i = 0; i < n; i++)
  {
    
    for (j = i; j < n; j++)
    {
      if (chars[i] != chars[j])
        break;
    }
    a += (char)chars[i];
    if (j > i + 1)
    {
      string temp =to_string(j-i);
      a+=temp;
    }
    i = j-1;
  }
  cout << a;
  return 0;
}
