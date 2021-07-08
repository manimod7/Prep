class Solution
{
public:
  int minAddToMakeValid(string s)
  {
    stack<int> stck;
    int res = 0;

    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '(')
        stck.push(i);
      else if (s[i] == ')')
      {
        if (stck.empty())
          res++;
        else
          stck.pop();
      }
    }
    return stck.size() + res;
  }
};