class Solution
{
public:
  /*
    We have to delete all the a's that are after b or/and all the b's that are before a
    We have to make minimum number of deletions
    dp[i] = number of deletions till i to make string valid
    
    Case - 1 s[i]='a'
      1. Remove 'a' => dp[i] = 1+dp[i-1]
      2. keep 'a'  =>(remove all the b's before this a) dp[i] = bcount
      
      We take the minimum of the two
      
      Case 2 -> s[i] = 'b'
      we keep the b and increase the count of b
      
    
    */

  int minimumDeletions(string s)
  {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    int bcount = 0;
    for (int i = 1; i <= n; i++)
    {
      if (s[i - 1] == 'a')
        dp[i] = min(dp[i - 1] + 1, bcount);
      else
      {
        dp[i] = dp[i - 1];
        bcount++;
      }
    }
    return dp[n];
  }
};