class Solution
{
public:
  bool visited[52][52];
  vector<vector<int>> graph;
  void dfs(int x, int y, int &area)
  {
    int m = graph.size(), n = graph[0].size();
    area++;
    visited[x][y] = true;

    if (x - 1 >= 0 && !visited[x - 1][y] && graph[x - 1][y] == 1)
      dfs(x - 1, y, area);

    if (x + 1 < m && !visited[x + 1][y] && graph[x + 1][y] == 1)
      dfs(x + 1, y, area);

    if (y - 1 >= 0 && !visited[x][y - 1] && graph[x][y - 1] == 1)
      dfs(x, y - 1, area);

    if (y + 1 < n && !visited[x][y + 1] && graph[x][y + 1] == 1)
      dfs(x, y + 1, area);
  }
  int maxAreaOfIsland(vector<vector<int>> &grid)
  {
    graph = grid;
    int area = 0, res = 0;
    int m = graph.size();
    int n = graph[0].size();
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!visited[i][j] && grid[i][j] == 1)
        {
          dfs(i, j, area);
          res = max(res, area);
          area = 0;
        }
      }
    }
    return res;
  }
};