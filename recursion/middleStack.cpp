#include <bits/stdc++.h>
using namespace std;

void deleteMid(stack<char> &st, int n,int curr )
{
  // If stack is empty or all items
  // are traversed
  if (st.empty() || curr == n)
    return;

  // Remove current item
  char x = st.top();
  st.pop();

  // Remove other items
  deleteMid(st, n, curr + 1);

  // Put all items back except middle
  if (curr != n / 2)
    st.push(x);
}
int main()
{
  stack<char> st;

  //push elements into the stack
  st.push('1');
  st.push('2');
  st.push('3');
  st.push('4');
  st.push('5');
  st.push('6');
  st.push('7');

  deleteMid(st, st.size(),0);
  while (!st.empty())
  {
    char p = st.top();
    st.pop();
    cout << p << " ";
  }
return 0;
}