class Solution
{
public:
  int scoreOfParentheses(string S)
  {
    stack<int> stack;
    stack.push(0);
    int ans = 0;

    for (char i : S)
    {
      if (i == '(')
      {
        stack.push(0);
      }
      else
      {
        int v = stack.top();
        stack.pop();
        int w = stack.top();
        stack.pop();
        stack.push(w + max(1, 2 * v));
      }
    }
    return stack.top();
  }
};