#include <bits/stdc++.h>
using namespace std;

void bottom_insert(stack<int> &st, int temp)
{

  if (st.empty())
    st.push(temp);
  else
  {
    int val = st.top();
    st.pop();
    bottom_insert(st, temp);
    st.push(val);
  }
}
void reverse(stack<int> &st){
  if(st.empty())
    return;
  
  int temp =st.top();
  st.pop();
  reverse(st);
  bottom_insert(st, temp);
  
}

int main(){
  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);
  st.push(6);
  reverse(st);
  return 0;
}
