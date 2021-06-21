class Solution
{
public:
  int maxProfit(int k, vector<int> &prices)
  {
    int len = prices.size();

    if (len <= 1 || k <= 0)
      return 0;

    if (k >= len / 2)
    {
      int profit = 0;
      for (int i = 1; i < len; i++)
      {
        if (prices[i] > prices[i - 1])
          profit += prices[i] - prices[i - 1];
      }
      return profit;
    }

    vector<int> buy(k, INT_MIN);
    vector<int> sell(k, 0);

    for (int i = 0; i < len; i++)
    {
      for (int j = 0; j < k; j++)
      {

        buy[j] = max(buy[j], (j == 0) ? -prices[i] : sell[j - 1] - prices[i]);
        sell[j] = max(sell[j], buy[j] + prices[i]);
      }
    }
    return sell[k - 1];
  }
};