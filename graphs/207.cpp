//* Course Schedule

class Solution
{
public:
  bool cycleTest(vector<vector<int>> &g, vector<int> &visited, int current, bool &ans)
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
    vector<int> visited(n, 0);
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
};