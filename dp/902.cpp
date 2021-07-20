class Solution
{
public:
  int solve(vector<string> &D, string &N1, int i, bool equal, vector<vector<int>> &dp)
  {

    int n = D.size();

    //Base Case

    //Check if subproblem solved
    if (dp[i][equal] != -1)
      return dp[i][equal];

    //Recursive Step
    //Equal
    int s1 = 0, s2 = 0;
    for (int j = 0; j < n; j++)
    {
      if ((D[j][0] - '0') > (N1[i] - '0'))
        continue;
      if ((D[j][0] - '0') < (N1[i] - '0'))
        s1++;
      if ((D[j][0] - '0') == (N1[i] - '0'))
        s2++;
    }

    if (equal)
    {
      if (i > 0)
        dp[i][equal] = dp[i - 1][equal] * s2;
      else
        dp[i][equal] = s2;
      return dp[i][equal];
    }
    else
    {

      //First take less than
      if (i > 0)
        dp[i][equal] = n * solve(D, N1, i - 1, equal, dp);
      else
        dp[i][equal] = 0;

      //Equal
      if (i > 0)
        dp[i][equal] += solve(D, N1, i - 1, 1 - equal, dp) * s1;
      else
        dp[i][equal] += s1;

      return dp[i][equal];
    }
  }

  int atMostNGivenDigitSet(vector<string> &D, int N)
  {

    string strN = to_string(N);
    int numDigits = strN.size(), n = D.size(), i, res = 0, prod = 1;

    vector<vector<int>> dp(10, vector<int>(2, -1));

    //Enumerate number of positive integers with exactly i digits

    for (i = 1; i <= numDigits; i++)
    {
      prod *= n;
      if (i < numDigits)
        res = res + prod;
      else
      {
        res += solve(D, strN, i - 1, 0, dp);
        res += solve(D, strN, i - 1, 1, dp);
      }
    }
    return res;
  }
};