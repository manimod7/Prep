class Solution
{
public:
  bool dfs(vector<vector<int>> &graph, vector<int> &visited, int startNode, int rank)
  {
    visited[startNode] = rank;
    int i, n = graph.size();
    bool t1 = false;
    for (i = 0; i < graph[startNode].size(); i++)
    {
      //Cross edge
      if (visited[graph[startNode][i]] == n + 1)
        continue;
      if (visited[graph[startNode][i]] == -1)
        t1 = t1 || dfs(graph, visited, graph[startNode][i], rank + 1);
      if (visited[graph[startNode][i]] < rank)
        return true;
    }
    visited[startNode] = n + 1;
    return t1;
  }
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {

    vector<vector<int>> graph(numCourses);
    int n = prerequisites.size();
    vector<int> visited(numCourses, -1);
    int i;
    bool res = false;
    //i->j if i is pre-req for j.
    for (i = 0; i < n; i++)
    {
      graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    for (i = 0; i < numCourses; i++)
    {
      if (visited[i] == -1)
      {
        res = res || dfs(graph, visited, i, 0);
      }
    }

    //Here we have an adjacency matrix where each row number is a pre requiste of all the courses in that row.

    return !res;
  }
};
