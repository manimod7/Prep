#include <bits/stdc++.h>
using namespace std;
bool dfs(unordered_map<int, vector<int>> &m, int node, map<int, int> &visited, int parent)
{
  if (visited[node] == 1)
    return true;

  visited[node] = 1;
  //  cout<<node<<" "<<visited.size()<<endl;
  for (int v : m[node])
  {
    if (v == parent)
      continue;
    if (visited.find(v) == visited.end() && dfs(m, v, visited, node))
    {
      return true;
    }
  }
  visited[node] = 2;

  return false;
}
int main(){
  vector<vector<int>> A{{1, 2}, {1, 3}, {2, 3}};
  int n = A.size();
  map<int, int> visited;

  unordered_map<int, vector<int>> m;
  
  for (int i = 0; i < n; i++)
  {
    int f = A[i][0];
    int s = A[i][1];

    m[f].push_back(s);
    //m[s].push_back(f);
    //  cout<<"***** "<<f<<" *****\n";
    if (dfs(m, f, visited, -1))
    {
      cout<<f<<"->"<<s;
    }
    visited.clear();
  }

  return 0;
}
