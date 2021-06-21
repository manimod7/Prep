class Solution
{
public:
  /*
      dp[i] has 2 states dp[i][0] & dp[i][1]
      We deduct the fee when we sell the stock
      
     A.  dp[i][0] means that I have no stock on i th day and dp[i][0] represents the max profit if I have no stock on ith day
      
        dp[i][0] will have 2 cases
        1. Either i sold the stock today -> dp[i][0] = dp[i-1][1]+ prices[i] -fee
      
        2. I did nothing today and have no stock -> dp[i][0] =dp[i-1][0]
        
        The ans would be the max of the two

     B.  dp[i][1] means that i have 1  stock on ith day and dp[i][1] represents the max profit if I have 1  stock on ith day
      
        1. I bought it today -> dp[i-1][0] - prices[i] 
        
        2. I have it from before -> dp[i][1] =dp[i-1][1]

*/

  int maxProfit(vector<int> &prices, int fee)
  {

    int n = prices.size();
    if (n <= 1)
      return 0;
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for (int i = 1; i < n; i++)
    {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[n - 1][0];
  }
};