class Solution
{
public:
  string str;
  int n;
  vector<vector<string>> res;
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
  void solve(int start, vector<string> currSet)
  {
    if (start == n)
    {
      res.push_back(currSet);
      return;
    }

    string temp;
    for (int k = start; k <= n; k++)
    {
      temp = str.substr(start, k - start + 1);
      if (isPalindrome(temp))
      {
        currSet.push_back(temp);
        solve(k + 1, currSet);
        currSet.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s)
  {
    vector<string> currSet;
    n = s.size();
    str = s;
    solve(0, currSet);
    return res;
  }
};