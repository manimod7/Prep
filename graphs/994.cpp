class Solution
{
public:
  bool isvalid(int i, int j, int m, int n)
  {
    if (i == m || j == n || j < 0 || i < 0)
      return false;
    return true;
  }
  int orangesRotting(vector<vector<int>> &grid)
  {
    int countFresh = 0;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
          countFresh++;
      }
    }
    if (countFresh == 0)
      return 0;
    queue<pair<int, int>> q;
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 2)
        {
          q.push({i, j});
        }
      }
    int maxVal = 0;
    while (!q.empty())
    {
      auto curr = q.front();
      q.pop();
      for (auto &x : dir)
      {
        int a = curr.first + x[0];
        int b = curr.second + x[1];
        if (isvalid(a, b, m, n) && grid[a][b] == 1)
        {
          countFresh--;
          q.push({a, b});
          grid[a][b] = grid[curr.first][curr.second] + 1;
          maxVal = max(maxVal, grid[a][b]);
        }
      }
    }
    if (countFresh)
      return -1;
    return maxVal - 2;
  }
};