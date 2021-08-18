#include<bits/stdc++.h>
using namespace std;

int main()
{
  stack<int> s;
  vector<int> arr{4,1,2,4,5,3,8,9,11,7,2};
  int n = arr.size();
  vector<int> nge(n,-1);
  for(int i=0;i<n;i++){
    if(s.empty()){
      s.push(i);
      continue;
    }
    while(!s.empty() && arr[i]> arr[s.top()]){
      int temp =arr[s.top()];
      nge[s.top()] =arr[i];
      s.pop();
    }
    s.push(i);
  }
  return 0;
}