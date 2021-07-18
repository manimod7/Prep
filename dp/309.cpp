/*
  We can have 2 possibilities
  
  Case 1 : I have a stock on day i

    1-> I bought the stock on day i => dp[i][1] =dp[i-2][0] -prices[i]  
        (i-2 is used since 1 day cooldown)

    2-> I have it from previous days -> dp[i][1] =dp[i-1][1]
    
  Case 2 : I don't have a stock on day i

    1-> I sold it today dp[i][0] -> dp[i-1][1] +prices[i]

    2-> I didn't have a stock yesterday as well ->dp[i][0] = dp[i-1][0]

*/

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {

    int n = prices.size();
    if (n <= 1)
      return 0;
    if (n == 2)
    {
      int profit = prices[1] - prices[0];
      if (profit >= 0)
        return profit;
      return 0;
    }

    vector<vector<int>> dp(n, vector<int>(2, 0));

    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
    dp[1][1] = max(dp[0][1], -prices[1]);

    for (int i = 2; i < n; i++)
    {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
    }
    return dp[n - 1][0];
  }
};