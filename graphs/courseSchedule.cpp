#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;
bool cycleTest(vector<vector<int>> &g, vector<bool> &visited, int current, bool &ans)
{
  visited[current] = 1; //processed
  if (ans == true)
    return true;
  for (auto nbr : g[current])
  {
    if (visited[nbr] == 1)
    {
      return ans = true;
    }
    else if (visited[nbr] == 0)
    {
      ans = ans || cycleTest(g, visited, nbr, ans);
    }
  }
  visited[current] = 2; //visited completely/processed completely
  return ans;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
  int n = numCourses;

  vector<vector<int>> g(n);

  for (int i = 0; i < prerequisites.size(); i++)
  {
    g[prerequisites[i][1]].push_back(prerequisites[i][0]);
  }
  vector<bool> visited(n, false);
  bool cycle = false;
  //bool current = false;
  for (int i = 0; i < g.size(); i++)
  {
    if (!visited[i])
    {
      cycle = cycle || cycleTest(g, visited, i, cycle);
      if (cycle == true)
        return false;
    }
  }
  return true;
}
int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt","w",stdout);
  #endif
  vector<vector<int>> c {{0,1}};
  canFinish(2,c);

  return 0;
}
