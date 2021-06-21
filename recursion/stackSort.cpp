#include <bits/stdc++.h>
using namespace std;
int main(){
  
  return 0;
}


void sort(stack<int> &s){
  if(s.size()==1)
    return;
    int temp = s.top();
    s.pop();
    sort(s);
    insert_bottom(s,temp);
}
void insert_bottom(stack<int> &s, int temp){
    if(s.size()==0||temp>=s.top()){
      s.push(temp);
    }
    else{
      int val =s.top();
      s.pop();
      insert_bottom(s, temp);
      s.push(val);
      return;
    }
}