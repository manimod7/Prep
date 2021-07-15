//Merge Intervals

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;
    if (intervals.size() == 0)
      return res;
    vector<int> prev = intervals[0];

    for (auto interval : intervals)
    {
      if (prev[1] >= interval[0])
      {
        prev[1] = max(prev[1], interval[1]);
      }
      else
      {
        res.push_back(prev);
        prev = interval;
      }
    }
    res.push_back(prev);
    return res;
  }
};