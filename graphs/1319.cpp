class Solution
{
public:
  void dfs(int u, vector<vector<int>> &graph, vector<bool> &vis)
  {

    if (vis[u])
      return;

    vis[u] = true;

    for (auto it : graph[u])
    {

      dfs(it, graph, vis);
    }
  }

  int makeConnected(int n, vector<vector<int>> &connections)
  {

    int len = connections.size();

    if (len < n - 1)
      return -1;

    vector<vector<int>> graph(n);

    int x, y;

    for (int i = 0; i < len; i++)
    {
      x = connections[i][0];
      y = connections[i][1];

      graph[x].push_back(y);
      graph[y].push_back(x);
    }

    int cnt = 0;
    vector<bool> vis(n, false);

    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {

        cnt++;

        dfs(i, graph, vis);
      }
    }
    return cnt - 1;
  }
};