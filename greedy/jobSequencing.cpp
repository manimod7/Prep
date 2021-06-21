class Solution
{
public:
  static bool comp(Job a, Job b)
  {
    return a.profit > b.profit;
  }
  //Function to find the maximum profit and the number of jobs done.
  vector<int> JobScheduling(Job arr[], int n)
  {
    // your code here

    sort(arr, arr + n, comp);
    vector<bool> done(n, false);
    int time = 0, cnt = 0, prof = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = min(n - 1, arr[i].dead - 1); j >= 0; j--)
      {
        if (done[j] == false)
        {
          done[j] = true;
          cnt++;
          prof += arr[i].profit;
          break;
        }
      }
    }
    return {cnt, prof};
  }
};