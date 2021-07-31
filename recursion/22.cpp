class Solution
{
public:
  vector<string> res;
  void solve(int open, int close, int n, string curr)
  {
    if (curr.size() == 2 * n)
    {
      res.push_back(curr);
      return;
    }
    if (open < n)
    {
      solve(open + 1, close, n, curr + "(");
    }
    if (close < open)
    {
      solve(open, close + 1, n, curr + ")");
    }
  }
  vector<string> generateParenthesis(int n)
  {
    solve(0, 0, n, "");
    return res;
  }
};