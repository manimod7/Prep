class Solution
{
public:
  bool isBiPartite(map<int, vector<int>> &graph, int n, int node, vector<int> &color)
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
  bool possibleBipartition(int n, vector<vector<int>> &dislikes)
  {

    map<int, vector<int>> graph;
    vector<int> color(n + 1, -1);
    for (int i = 0; i < dislikes.size(); i++)
    {
      graph[dislikes[i][0]].push_back(dislikes[i][1]);
      graph[dislikes[i][1]].push_back(dislikes[i][0]);
    }
    for (int i = 1; i <= n; i++)
    {
      if (color[i] == -1)
        if (!isBiPartite(graph, n, i, color))
          return false;
    }
    return true;
  }
};