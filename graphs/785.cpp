class Solution
{
public:
  bool isBiPartite(vector<vector<int>> &graph, int node, vector<int> &color)
  {
    queue<int> q;
    q.push(node);
    color[node] = 1;
    while (!q.empty())
    {
      int curr = q.front();
      q.pop();
      for (int j : graph[curr])
      {
        if (color[j] == -1)
        {
          color[j] = 1 - color[curr];
          q.push(j);
        }
        if (color[j] == color[curr])
          return false;
      }
    }
    return true;
  }
  bool isBipartite(vector<vector<int>> &graph)
  {
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
      if (color[i] == -1)
        if (!isBiPartite(graph, i, color))
          return false;
    }
    return true;
  }
};