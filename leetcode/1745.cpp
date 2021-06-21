#include <bits/stdc++.h>
using namespace std;
bool flag = false;
string str = "";

bool isPalindrome(string s)
{
  int n = s.size();
  int i = 0, j = n - 1;
  while (i <= j)
  {
    if (s[i] != s[j])
      return false;
    i++;
    j--;
  }
  return true;
}

void solve(int start, int end, int k)
{

  if (start >end)
    return;
  if (flag == true)
    return;
  if (k == 0)
  {
    if (start <= end)
    {
      if (isPalindrome(str.substr(start)))
      {
        flag = true;
        return;
      }
    }
    return;
  }

  for (int i = start; i < end; i++)
  {
    if (flag == true)
      break;
    string temp = str.substr(start, i - start );
    if (isPalindrome(temp))
    {
      solve(i + 1, end, k - 1);
    }
  }
}
bool checkPartitioning(string s)
{
  solve(0, s.size() - 1, 2);
  str = s;
  return flag;
}
int main(){
  checkPartitioning("abcd");
  return 0;
}
