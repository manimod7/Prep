class Solution
{
public:
  void dfs(vector<vector<int>> &grid, int x, int y, vector<vector<bool>> &visited)
  {

    int m = grid.size(), n = grid[0].size();

    //Traverse all neighbours of (x, y)
    grid[x][y] = 0;
    visited[x][y] = true;

    if (x + 1 < m && grid[x + 1][y] == 1 && !visited[x + 1][y])
      dfs(grid, x + 1, y, visited);
    if (x - 1 >= 0 && grid[x - 1][y] == 1 && !visited[x - 1][y])
      dfs(grid, x - 1, y, visited);
    if (y + 1 < n && grid[x][y + 1] == 1 && !visited[x][y + 1])
      dfs(grid, x, y + 1, visited);
    if (y - 1 >= 0 && grid[x][y - 1] == 1 && !visited[x][y - 1])
      dfs(grid, x, y - 1, visited);
  }

  int numEnclaves(vector<vector<int>> &grid)
  {

    int m = grid.size(), n = grid[0].size(), res = 0;

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        bool valid = (i == 0 || i == m - 1 || j == 0 || j == n - 1);
        if (valid && grid[i][j] == 1 && !visited[i][j])
          dfs(grid, i, j, visited);
      }
    }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
          res += 1;
      }
    }
    return res;
  }
};