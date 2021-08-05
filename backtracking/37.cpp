//row[i][j] represents that if in row i of the sudoku board, number j is there or not
//col[i][j] represents that if in col i of the sudoku board, number j is there or not
//rowId -> current row
//colId -> current col
//currSet -> current state of sudoku board
//res is the final ans

class Solution
{
public:
  vector<vector<char>> ans;
  void solve(vector<vector<bool>> &row, vector<vector<bool>> &col, vector<vector<bool>> &box, int rowId, int colId, vector<vector<char>> &currBoard, vector<vector<char>> &res)
  {

    if (rowId == 9)
    {
      res = currBoard;
      return;
    }
    if (currBoard[rowId][colId] != '.')
    {

      if (colId == 8)
        solve(row, col, box, rowId + 1, 0, currBoard, res);
      else
        solve(row, col, box, rowId, colId + 1, currBoard, res);
      // return;
    }
    else
    {
      for (int i = 1; i <= 9; i++)
      {
        if (!row[rowId][i - 1] && !col[colId][i - 1] && !box[3 * (rowId / 3) + (colId / 3)][i - 1])
        {
          currBoard[rowId][colId] = (char)('0' + i);
          row[rowId][i - 1] = true;
          col[colId][i - 1] = true;
          box[3 * (rowId / 3) + (colId / 3)][i - 1] = true;

          if (colId == 8)
            solve(row, col, box, rowId + 1, 0, currBoard, res);
          else
            solve(row, col, box, rowId, colId + 1, currBoard, res);

          //Backtracking
          currBoard[rowId][colId] = '.';
          row[rowId][i - 1] = false;
          col[colId][i - 1] = false;
          box[3 * (rowId / 3) + (colId / 3)][i - 1] = false;
        }
      }
    }
  }
  void solveSudoku(vector<vector<char>> &board)
  {
    vector<vector<bool>> row(9, vector<bool>(9, false));
    vector<vector<bool>> col(9, vector<bool>(9, false));
    vector<vector<bool>> box(9, vector<bool>(9, false));
    int i, j;

    for (i = 0; i < 9; i++)
    {
      for (j = 0; j < 9; j++)
      {
        if (board[i][j] != '.')
        {
          row[i][(board[i][j] - '0') - 1] = true;
          col[j][(board[i][j] - '0') - 1] = true;
          box[3 * (i / 3) + j / 3][(board[i][j] - '0') - 1] = true;
        }
      }
    }
    vector<vector<char>> currSet = board;
    vector<vector<char>> res;
    solve(row, col, box, 0, 0, currSet, res);
    board = res;
  }
};