class Solution
{
public:
  int maxPoints(vector<vector<int>> &points)
  {
    int ans = 0;
    for (int i = 0; i < points.size(); i++)
    {
      int same = 1, res = 0;
      unordered_map<long double, int> h;
      for (int j = i + 1; j < points.size(); j++)
      {
        if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
        {
          same++;
        }
        else if (points[i][0] == points[j][0])
        {
          h[INT_MAX]++;
        }
        else
        {
          long double slope = (long double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
          h[slope]++;
        }
      }
      for (auto l : h)
      {
        res = max(res, l.second);
      }
      res += same;
      ans = max(ans, res);
    }
    return ans;
  }
};