#include<bits/stdc++.h>
using namespace std;

int main()
{               //-1  4  4 -1 -1  5 -1 -1  -1 11  7
            //    0   1  2  3  4  5  6  7  8  9  10
  vector<int> arr{4,  1, 2, 4, 5, 3, 8, 9, 11, 7, 2};
  int n = arr.size();
  stack<int> s;
  vector<int> pge(n, -1);
  for(int i=n-1;i>=0;i--){
    if(s.empty()){
      s.push(i);
      continue;
    }
    while(!s.empty() and arr[s.top()]<arr[i]){
      int index = s.top();
      s.pop();
      pge[index] = arr[i];
    }
    s.push(i);
  }
  return 0;
}