class Solution
{
public:
  bool cmp(vector<int> &a, vector<int> &b)
  {
    return a[1] <= b[1];
  }
  int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
  {
    int n = profit.size();
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
      dp[i][0] = startTime[i];
      dp[i][1] = endTime[i];
      dp[i][2] = profit[i];
      //dp[i][3] = profit[i];
    }

    sort(dp.begin(), dp.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });

    int mx[n];
    mx[0] = dp[0][2];

    for (int i = 1; i < n; i++)
    {
      int inc = dp[i][2];
      int last = -1;
      int low = 0;
      int high = i - 1;
      while (low <= high)
      {
        int mid = (low + high) / 2;
        if (dp[mid][1] <= dp[i][0])
        {
          last = mid;
          low = mid + 1;
        }
        else
          high = mid - 1;
      }
      if (last != -1)
        inc += mx[last];
      int exc = mx[i - 1];
      mx[i] = max(inc, exc);
    }
    return mx[n - 1];
  }
};