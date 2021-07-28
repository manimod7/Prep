#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int main(){
                        // 0     1   2     3      4      5   6   7
  vector<vector<int>> g{{1,2,3},{0},{0,4},{0,6},{1,2,4,5},{4},{3,7},{6}};
  // stack<int> s;
  vector<int> visited(g.size(), 0);
  int start=0; //start node
  

  stack<int> s;
  s.push(start);
  visited[start] = 1;

  while(!s.empty()){
    int current =s.top();
    s.pop();
    cout<<current<<endl;
    for(auto nbr : g[current]){
      if(!visited[nbr]){
        visited[nbr]=1;
        s.push(nbr);
      }
    }
  }

  return 0;
}
