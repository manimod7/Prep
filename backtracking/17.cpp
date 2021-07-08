#include <bits/stdc++.h>
using namespace std;

vector<string> funcFunny(string digits);
int main(){
  string digits ="23";
  funcFunny(digits);
  return 0;
}
unordered_map<char, string> m;
void solve(string digits, string &ans, vector<string> &res, int index)
{
  if (ans.size() == digits.size() || index == digits.size())
  {
    res.push_back(ans);
    return;
  }
  int n = 3;
  if (digits[index] == '7' || digits[index] == '9')
    n = 4;
  char x = digits[index];
  string temp = m[x];
  for (int i = 0; i < n; i++)
  {
    ans += temp[i];
    solve(digits, ans, res, index + 1);
    ans.pop_back();
  }
}
vector<string> funcFunny(string digits)
{

  m['2'] = "abc";
  m['3'] = "def";
  m['4'] = "ghi";
  m['5'] = "jkl";
  m['6'] = "mno";
  m['7'] = "pqrs";
  m['8'] = "tuv";
  m['9'] = "wxyz";

  string ans;
  vector<string> res;
  solve(digits, ans, res, 0);
  return res;
}
