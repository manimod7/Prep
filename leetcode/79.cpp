class Solution
{
public:
  bool ans = false;

  void solve(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col, int m, int n, string currWord, string target)
  {
    if (ans == true)
      return;
    if (target.substr(0, currWord.size()) != currWord)
      return;
    if (row < 0 || row >= m || col < 0 || col >= n)
      return;

    if (currWord == target)
    {
      ans = true;
      return;
    }
    if (currWord.size() >= target.size())
      return;

    //Assignment
    currWord += (char)board[row][col];
    visited[row][col] = true;
    if (currWord == target)
    {
      ans = true;
      return;
    }
    //Recursive Step
    if (row + 1 < m && !visited[row + 1][col])
    {
      solve(board, visited, row + 1, col, m, n, currWord, target);
    }

    if (row - 1 >= 0 && !visited[row - 1][col])
    {
      solve(board, visited, row - 1, col, m, n, currWord, target);
    }

    if (col + 1 < n && !visited[row][col + 1])
    {
      solve(board, visited, row, col + 1, m, n, currWord, target);
    }

    if (col - 1 >= 0 && !visited[row][col - 1])
    {
      solve(board, visited, row, col - 1, m, n, currWord, target);
    }

    //Backtracking
    visited[row][col] = false;
    currWord.pop_back();
  }
  bool exist(vector<vector<char>> &board, string word)
  {
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (ans)
          return true;
        solve(board, visited, i, j, m, n, "", word);
      }
    }
    return ans;
  }
};