class Solution
{
public:
  bool backspaceCompare(string S, string T)
  {
    stack<char> s1, s2;
    for (int i = 0; i < S.size(); i++)
    {
      if (S[i] != '#')
      {
        s1.push(S[i]);
      }
      else if (!s1.empty())
      {
        s1.pop();
      }
    }
    for (int i = 0; i < T.size(); i++)
    {
      if (T[i] != '#')
        s2.push(T[i]);
      else if (!s2.empty())
        s2.pop();
    }
    if (s1.size() != s2.size())
      return false;
    while (!s1.empty() && !s2.empty())
    {
      char a = s1.top(), b = s2.top();
      s1.pop();
      s2.pop();
      if (a != b)
        return false;
    }
    return true;
  }
};