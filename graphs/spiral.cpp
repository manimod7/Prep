class Solution
{
public:
  bool visited[103][103];
  vector<int> vec;
  int m, n;
  // void down(int i, int j, vector<vector<int>> &matrix);
  // void up(int i, int j, vector<vector<int>> &matrix);
  // void left(int i, int j, vector<vector<int>> &matrix);
  // void right(int i, int j, vector<vector<int>> &matrix);

  void right(int i, int j, vector<vector<int>> &matrix)
  {
    if (i >= m || j >= n || i < 0 || j < 0)
      return;
    visited[i][j] = true;
    vec.push_back(matrix[i][j]);
    if (!visited[i][j + 1])
      right(i, j + 1, matrix);
    if (!visited[i + 1][j])
      down(i + 1, j, matrix);
  }
  void down(int i, int j, vector<vector<int>> &matrix)
  {
    if (i >= m || j >= n || i < 0 || j < 0)
      return;
    visited[i][j] = true;
    vec.push_back(matrix[i][j]);
    if (!visited[i + 1][j])
      down(i + 1, j, matrix);
    if (!visited[i][j - 1])
      left(i, j - 1, matrix);
  }
  void left(int i, int j, vector<vector<int>> &matrix)
  {
    if (i >= m || j >= n || i < 0 || j < 0)
      return;
    visited[i][j] = true;
    vec.push_back(matrix[i][j]);
    if (!visited[i][j - 1])
      left(i, j - 1, matrix);
    if (!visited[i - 1][j])
      up(i - 1, j, matrix);
  }
  void up(int i, int j, vector<vector<int>> &matrix)
  {
    if (i >= m || j >= n || i < 0 || j < 0)
      return;
    visited[i][j] = true;
    vec.push_back(matrix[i][j]);
    if (!visited[i - 1][j])
      up(i - 1, j, matrix);
    if (!visited[i][j + 1])
      right(i, j + 1, matrix);
  }
  //Function to return a list of integers denoting spiral traversal of matrix.
  vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
  {
    // code here
    memset(visited, false, sizeof(visited));
    m = r, n = c;
    right(0, 0, matrix);
    return vec;
  }
};