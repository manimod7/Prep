#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> nums {1,2,3,4,5,-1};
  int n = nums.size();

  //*Subsets with sum = 4  (1,3), (4),   (2,3,-1),  (5,-1),     (4,1,-1)
  //*Subsets with sum = 5  (5),   (4,1), (2,3),     (2,3,1,-1), (5,1,-1) (4,2,-1)
  //*Subsets with sum = 3  (1,2), (3),   (4,-1),    (3,1,-1)
  
  int givenSum =3;

  int totalSum=0;
  for(int i=0;i<n;i++){
    totalSum+=nums[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(totalSum + 1, 0));
  for (int i = 0; i <= n; i++)
  {
    dp[i][0] = 1;
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=totalSum;j++){
      if(nums[i-1]<=j)
        dp[i][j] = dp[i-1][j]+dp[i-1][j-nums[i-1]];
      else
        dp[i][j] = dp[i-1][j];
    }
  }
  cout<<dp[n][givenSum];
  return 0;
}
