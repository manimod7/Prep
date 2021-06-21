#include <bits/stdc++.h>
using namespace std;

void _union(int a, int b, vector<int> &parent)
{
  parent[a] = b;
}
int find(int x, vector<int> &parent)
{
  if (parent[x] == -1)
    return x;
  return parent[x] = find(parent[x],parent);
}
int main(){
  
  vector<int> parent(4,-1);
  vector<vector<int>> edges {{1,2},{2,3},{1,3}};
  for (int i = 0; i < edges.size(); i++)
  {
    int from = edges[i][0], to = edges[i][1];
    int fromP = find(from, parent);
    int toP = find(to, parent);
    if (fromP == toP)
      cout<<from<<"->"<<to;
    _union(from, to, parent);
  }
return 0;
}
