class Solution
{
public:
  int dp[101][101];
  int solve(vector<int> &a, int i, int j)
  {
    if (i >= j)
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    int minAns = INT_MAX;
    for (int k = i; k < j; k++)
    {
      int tempAns = solve(a, i, k) + solve(a, k + 1, j) + (a[i - 1] * a[k] * a[j]);
      if (tempAns < minAns)
        minAns = tempAns;
    }

    return dp[i][j] = minAns;
  }
  int matrixMultiplication(int N, int arr[])
  {
    // code here
    int i = 1, j = N - 1;
    vector<int> a;
    for (int i = 0; i < N; i++)
      a.push_back(arr[i]);
    memset(dp, -1, sizeof(dp));
    int ans = solve(a, i, j);
    return ans;
  }
};