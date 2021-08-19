#include<bits/stdc++.h>
using namespace std;

bool HasHigherPrecedence(char c1, char c2)
{
  if (c1 == '+' || c1 == '-')
    return c2 == '+' || c2 == '-';
  return true;
}
int calculate(string s)
{
  s += " ";
  vector<string> postfix;
  stack<char> st;
  // Convert this infix to Postfix.
  // Parse the expression.
  string curr_num = "";
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != ' ')
    {
      curr_num += s[i];
      continue;
    }

    if (curr_num != "")
    {
      postfix.push_back(curr_num);
      curr_num = "";
    }

    if (s[i] == ' ')
      continue;
    while (!st.empty() && HasHigherPrecedence(st.top(), s[i]))
    {
      postfix.push_back(string(1, st.top()));
      st.pop();
    }
    st.push(s[i]);
  }
  while (!st.empty())
  {
    postfix.push_back(string(1, st.top()));
    st.pop();
  }
  // Evaluate this postfix.
  stack<int> st2;
  for (int i = 0; i < postfix.size(); i++)
  {
    if (postfix[i] != "+" && postfix[i] != "-" && postfix[i] != "*" && postfix[i] != "/")
    {
      st2.push(stoi(postfix[i]));
      continue;
    }
    int op2 = st2.top();
    st2.pop();
    int op1 = st2.top();
    st2.pop();
    if (postfix[i] == "+")
      st2.push(op1 + op2);
    else if (postfix[i] == "-")
      st2.push(op1 - op2);
    else if (postfix[i] == "*")
      st2.push(op1 * op2);
    else
      st2.push(op1 / op2);
  }

  int main()
  {

    return 0;
  }