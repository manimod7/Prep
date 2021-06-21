#include <bits/stdc++.h>
using namespace std;
int main(){
  string s = "(()))";
  //  (  (  )  )  )
  //  0  1  2  3  4
  int n = s.size(),
  left = 0, right = 0;
  stack<int> st;

  for (int i = 0; i < n; i++)
  {
    if (s[i] == '(')
      st.push(i);
    if (s[i] == ')')
    {
      if (i + 1 < n)
      {
        if (s[i + 1] == '('){
          right++;
          if(st.empty())
            left++;
        }
          
        else if (s[i + 1] == ')' && !st.empty())
        {
          st.pop();
          i+=1;
          continue;
        }
        else if (s[i + 1] == ')' && st.empty()){
          left++;
          i++;
        }
      }
    }
    if (i + 1 == n)
      right++;
  }
  return 0;
}
