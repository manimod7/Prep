class Solution
{
public:
  int max(int a, int b)
  {
    return a >= b ? a : b;
  }
  int maxDepth(string s)
  {
    stack<int> st;
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '(')
      {
        if (st.empty())
          st.push(1);
        else
          st.push(st.top() + 1);
        res = max(res, st.top());
      }
      else if (s[i] == ')')
        st.pop();
    }
    return res;
  }
};