class Solution
{
public:
  vector<string> res;
  string st;
  int size;
  void solve(int start, int dots, string curr)
  {
    if (start >= size)
      return;

    string remain = st.substr(start);
    int n = remain.size();

    if (dots == 3 && n == 0)
      return;
    if (dots == 3 && n > 0)
    {
      if (n > 1 && remain[0] == '0')
        return;
      if (n > 3)
        return;
      if (remain == "")
        return;
      int currInt = stoi(remain);
      if (currInt >= 0 && currInt <= 255)
      {
        curr += remain;
        res.push_back(curr);
        return;
      }
    }
    int len = min(n, 3);
    if (dots < 3)
    {
      for (int i = start; i < start + len; i++)
      {
        string left = st.substr(start, i - start + 1);
        if (left.size() > 1 && left[0] == '0')
          return;
        if (left == "")
          continue;
        int currInst = stoi(left);
        if (currInst >= 0 && currInst <= 255)
        {
          string currAns = curr + left + ".";
          solve(i + 1, dots + 1, currAns);
        }
      }
    }
  }
  vector<string> restoreIpAddresses(string s)
  {
    st = s;
    size = s.size();
    solve(0, 0, "");
    return res;
  }
};