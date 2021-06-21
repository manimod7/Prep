#include <bits/stdc++.h>
using namespace std;
double dp[102][102];
double sum[102][102];
vector<int> num;
double solve(int i, int j, int k)
{
  int n = num.size();
  if (i >= n || j >= n)
    return 0;
  if (i > j)
    return 0;
  if (k == 1)
    return (double)sum[i][j] / (j - i + 1);
  if (i == j)
    return dp[i][j] = sum[i][j];
  // if(dp[i][j]!=-1.00)
  //     return dp[i][j];

  double res = INT_MIN;
  for (int x = i; x < j; x++)
  {
    double temp = solve(i, x, k - 1) + ((sum[x + 1][j]) / (j - x));
    res = max(temp, res);
    //cout<<0;
  }
  return dp[i][j] = res;
}
int main(){
  int k =27;
  vector<int> nums {4663, 3020, 7789, 1627, 9668, 1356, 4207, 1133, 8765, 4649, 205, 6455, 8864, 3554, 3916, 5925, 3995, 4540, 3487, 5444, 8259, 8802, 6777, 7306, 989, 4958, 2921, 8155, 4922, 2469, 6923, 776, 9777, 1796, 708, 786, 3158, 7369, 8715, 2136, 2510, 3739, 6411, 7996, 6211, 8282, 4805, 236, 1489, 7698 };
  int n = nums.size();
  cout<<n;
  //memset(sum,0.00,sizeof(sum));
  num = nums;
  // for(int i=0;i<102;i++){
  //     for(int j=0;j<102;j++){
  //         sum[i][j] =0;
  //         dp[i][j]=-1;
  //     }
  // }
  //memset(dp,-1.00,sizeof(dp));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        sum[i][j] = nums[i];
      else if (i > j)
        sum[i][j] = 0;
      else
        sum[i][j] = sum[i][j - 1] + nums[j];
    }
  }
  double ans = solve(0, n - 1, k);
  // for(int i=0;i<n;i++){
  //     for(int j=0;j<n;j++)
  //         cout<<dp[i][j]<<" ";
  //     cout<<endl;
  // }
  cout<<ans;
  return 0;
}
