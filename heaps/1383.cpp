class Solution
{
public:
  int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
  {
    vector<pair<int, int>> v;
    priority_queue<int, vector<int>, greater<int>> s;
    long sum = 0, res = 0;
    for (auto i = 0; i < n; ++i)
      v.push_back({efficiency[i], speed[i]});
    sort(v.begin(), v.end());
    for (auto i = n - 1; i >= 0; --i)
    {
      sum += v[i].second;
      s.push(v[i].second);
      if (s.size() > k)
      {
        sum -= s.top();
        s.pop();
      }
      res = max(res, sum * v[i].first);
    }
    return res % 1000000007;
  }
};