#include<bits/stdc++.h>
using namespace std;

int main(){
  int arr[5] {1,2,3,4,6};
  int N=5;
  int sum = 0;
  for (int i = 0; i < N; i++)
  {
    sum += arr[i];
  }
  if (sum % 2 == 1)
    return 0;
  sum /= 2;
  vector<vector<bool>> dp(N + 1, vector<bool>(sum + 1, false));
  for (int i = 0; i < N + 1; i++)
    dp[i][0] = true;
  for (int i = 1; i < N + 1; i++)
  {
    for (int j = 1; j < sum + 1; j++)
    {
      if (arr[i] <= j)
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  cout<<dp[N][sum];
  return 0;
}