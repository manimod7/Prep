#include <bits/stdc++.h>
using namespace std;
int main(){
  int ans =0;
  map<int, vector<int>> graph;
  //Graph Construction
  int n=5;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (j == i + 1 || j == 3 * i)
      {
        graph[i].push_back(j);
      }
    }
  }
  vector<bool> visited(n + 1, false);
  visited[1] = true;
  int currNode=1, currDist=0;
  queue<pair<int, int>> q;
  q.push({1, 0});
  while (!q.empty())
  {
    pair<int, int> frnt = q.front();
    q.pop();
    currNode = frnt.first;
    currDist = frnt.second;
    if (currNode == n)
      cout<<currDist;
    for (auto nbr : graph[currNode])
    {
      if (!visited[nbr])
      {
        q.push({nbr, currDist + 1});
        visited[nbr] = true;
      }
    }
  }
  // return -1;
  return 0;
}
