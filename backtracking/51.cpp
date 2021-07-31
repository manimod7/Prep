class Solution
{
public:
  vector<vector<string>> res;
  int N;
  bool isValid(int i, int j)
  {
    if (i >= 0 && j >= 0 && i < N && j < N)
      return true;
    return false;
  }
  bool canPlace(int x, int y, vector<string> &s)
  {
    int i = x, j = y;
    while (isValid(i, j))
    {
      if (s[i][j] == 'Q')
        return false;
      i--;
    }
    i = x, j = y;
    while (isValid(i, j))
    {
      if (s[i][j] == 'Q')
        return false;
      i--, j--;
    }
    i = x, j = y;
    while (isValid(i, j))
    {
      if (s[i][j] == 'Q')
        return false;
      i--, j++;
    }
    i = x, j = y;
    return true;
  }
  void nQueens(int row, vector<string> &temp)
  {
    if (row == N)
    {
      res.push_back(temp);
      return;
    }
    for (int col = 0; col < N; col++)
    {
      if (canPlace(row, col, temp))
      {
        temp[row][col] = 'Q';
        nQueens(row + 1, temp);
        temp[row][col] = '.';
      }
    }
  }
  vector<vector<string>> solveNQueens(int n)
  {
    string s;
    N = n;
    for (int i = 0; i < n; i++)
    {
      s += ".";
    }
    vector<string> temp(n, s);
    nQueens(0, temp);
    return res;
  }
};