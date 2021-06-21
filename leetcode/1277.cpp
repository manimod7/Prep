class Solution
{
public:
  int countSquares(vector<vector<int>> &matrix)
  {
    int ans = 0;
    int m = matrix.size(), n = matrix[0].size();

    for (int i = 0; i < m; i++)
      if (matrix[i][0])
        ans++;
    for (int j = 1; j < n; j++)
      if (matrix[0][j])
        ans++;
    for (int i = 1; i < m; i++)
    {
      for (int j = 1; j < n; j++)
      {
        if (matrix[i][j])
        {
          matrix[i][j] = 1 + min({matrix[i - 1][j - 1],
                                  matrix[i][j - 1],
                                  matrix[i - 1][j]});
          ans += matrix[i][j];
        }
      }
    }
    return ans;
  }
};