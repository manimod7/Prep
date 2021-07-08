class Solution
{
public:
  string minRemoveToMakeValid(string s)
  {
    int n = s.size();
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
      if (s[i] == '(')
      {
        st.push(i);
      }
      else if (s[i] == ')' && !st.empty())
        st.pop();
      else if (s[i] == ')' && st.empty())
        s[i] = '*';
    }
    while (!st.empty())
    {
      s[st.top()] = '*';
      st.pop();
    }
    string ans;
    for (int i = 0; i < n; i++)
    {
      if (s[i] != '*')
        ans += s[i];
    }
    return ans;
  }
};