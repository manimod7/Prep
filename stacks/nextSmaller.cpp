#include<bits/stdc++.h>
using namespace std;

int main()
{               //1 -1 -1  3  3  2  7  7  7   2 -1
  vector<int> arr{4, 1, 2, 4, 5, 3, 8, 9, 11, 7, 2};
  int n = arr.size();
  vector<int> nse(n, -1);
  stack<int> s;
  for(int i=0;i<n;i++){
    if(s.empty()){
      s.push(i);
      continue;
    }
    while(!s.empty() && arr[i]>arr[s.top()]){
      int indx = s.top();
      s.pop();
      nse[indx] =arr[i];
    }
    s.push(i);
  }
  return 0;
}