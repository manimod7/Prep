class Solution
{
public:
  int DFS(vector<vector<int>> &matrix, int i, int j, int val, vector<vector<int>> &hash)
  {
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
      return 0;
    if (matrix[i][j] > val)
    {
      if (hash[i][j] != 0)
        return hash[i][j]; //if this path has been searched
      int a = DFS(matrix, i, j + 1, matrix[i][j], hash) + 1;
      int b = DFS(matrix, i, j - 1, matrix[i][j], hash) + 1;
      int c = DFS(matrix, i + 1, j, matrix[i][j], hash) + 1;
      int d = DFS(matrix, i - 1, j, matrix[i][j], hash) + 1;
      hash[i][j] = max(a, max(b, max(c, d)));
      return hash[i][j];
    }
    return 0;
  }
  int longestIncreasingPath(vector<vector<int>> &matrix)
  {
    if (matrix.size() == 0)
      return 0;
    int Max = 0;
    // vector<int> tem(matrix[0].size(),0);
    vector<vector<int>> hash(matrix.size(), vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++)
      for (int j = 0; j < matrix[0].size(); j++)
        Max = max(DFS(matrix, i, j, INT_MIN, hash), Max);
    for (int i = 0; i < hash.size(); i++)
    {
      for (int j = 0; j < hash[0].size(); j++)
      {
        cout << hash[i][j] << " ";
      }
      cout << endl;
    }
    return Max;
  }
};