#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ans = 0;
void solve(string s, int start, int end, vector<int> st)
{
  if (start >= end)
  {
    ans++;
    return;
  }
  if (s[start] == '0')
    return;
  for (int i = start; i < end; i++)
  {
    if(s[start]=='0')
    return;
    string temp = s.substr(start, i - start + 1);
    int tempNumber = stoi(temp);
    if ((st.empty())||tempNumber > st[st.size() - 1])
    {
      st.push_back(tempNumber);
      solve(s, i + 1, end, st);
      st.pop_back();
    }
  }
}
int main()
{

  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n=4, s=1045;
  

  string ex = to_string(s);
  // n = ex.size();
  vector<int> tmp;
  solve(ex, 0, n, tmp);
  cout << ans;
  return 0;
}