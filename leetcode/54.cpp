#include <bits/stdc++.h>
#include<vector>
using namespace std;

bool visited[13][13];
vector<int> vec;
int m, n;
void down(int i, int j, vector<vector<int>> &matrix);
void up(int i, int j, vector<vector<int>> &matrix);
void left(int i, int j, vector<vector<int>> &matrix);

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
vector<int> spiralOrder(vector<vector<int>> &matrix)
{

  right(0, 0, matrix);
  return vec;
}
int main(){

  vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  memset(visited, false, sizeof(visited));
  int m = matrix.size(), n = matrix[0].size();
  spiralOrder(matrix);
  cout<<"Done";
  return 0;
}
