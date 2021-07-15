class Solution
{
public:
  int findMinArrowShots(vector<vector<int>> &points)
  {
    int cnt = 1;
    sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b)
          {
            if (a[1] == b[1])
              return a[0] <= b[0];
            return a[1] <= b[1];
          }); //Sort in ascending order w.r.t end points
    int n = points.size();
    vector<int> top = points[0];
    for (int i = 0; i < n; i++)
    {
      if (top[1] >= points[i][0])
        continue;
      else
      {
        cnt++;
        top = points[i];
      }
    }
    return cnt;
  }
};