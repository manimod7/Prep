#include <bits/stdc++.h>
using namespace std;
//Topological Sort
void dfs(vector<vector<int>> &g, int v, vector<bool> &visited, stack<int> &st){
  visited[v] = true;
  for(int i=0;i<g[v].size();i++){
    if(!visited[g[v][i]]){
      dfs(g, g[v][i], visited, st);
    }
  }
  st.push(v);
}
int main(){
  vector<vector<int>> g {{2,3},{},{},{1},{1,2},{0,2}};
  vector<bool> visited (6,false);
  stack<int> st;
  int n = g.size();
  for(auto i=0;i<n;i++){
    if(!visited[i])
      dfs(g,i,visited,st);
  }
  vector<int> ans;
  while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
  }
  for(int i=0;i<ans.size();i++)
  cout<<ans[i]<<" ";
  return 0;
}
