class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {

    int n = prices.size();
    int fb = INT_MIN, sb = INT_MIN, fs = INT_MIN, ss = INT_MIN;
    //first buy    second buy    first sell    second sell

    for (int i = 0; i < n; i++)
    {
      fb = max(fb, -prices[i]);
      fs = max(fs, fb + prices[i]);
      sb = max(sb, fs - prices[i]);
      ss = max(ss, sb + prices[i]);
    }
    return ss;
  }
};

/*
Method 2

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        if(n==0)
            return 0;
        
        vector<int> left(n,0),right(n,0);
        int leftMin = prices[0];
        
        for(int i=1;i<n;++i)
        {
            left[i] = max(left[i-1],prices[i]-leftMin);
            leftMin = min(leftMin,prices[i]);
        }
        
        int rightMax = prices[n-1];
        
        for(int i=n-2;i>=0;--i)
        {
            right[i] = max(right[i+1],rightMax-prices[i]);
            rightMax = max(rightMax,prices[i]);
        }
        
        int profit = right[0];
        
        for(int i=1;i<n;++i)
            profit = max(profit,left[i-1]+right[i]);
        
        return profit;
    }
};

*/