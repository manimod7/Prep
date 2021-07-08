class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &t)
  {
    vector<int> res(t.size());
    stack<int> ans;
    for (int i = t.size() - 1; i >= 0; i--)
    {
      while (!ans.empty() && t[ans.top()] <= t[i])
        ans.pop();
      if (ans.empty())
        res[i] = 0;
      else
        res[i] = ans.top() - i;
      ans.push(i);
    }
    return res;
  }
};

