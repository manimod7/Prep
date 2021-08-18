#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> arr{4, 1, 2, 4, 5, 3, 8, 9, 11, 7, 2};
  int n = arr.size();
  stack<int> s;
  vector<int> pse(n, -1);
  for(int i=n-1;i>=0;i--){
    if(s.empty()){
      s.push(i);
      continue;
    }
    while(!s.empty() && arr[s.top()]>arr[i]){
        int indx = s.top();
        s.pop();
        pse[indx] =arr[i];
    }
    s.push(i);
  }
  return 0;
}