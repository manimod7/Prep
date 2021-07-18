class Solution
{
public:
  //Function to find the maximum number of meetings that can
  //be performed in a meeting room.
  int maxMeetings(int start[], int end[], int n)
  {
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; i++)
    {
      v.push_back({end[i], {start[i], i}});
    }
    sort(v.begin(), v.end());
    if (v.size() == 0)
    {
      return 0;
    }
    int count = 1;
    int pm = v[0].first;

    for (int i = 1; i < v.size(); i++)
    {
      if (v[i].second.first > pm)
      {
        count++;
        pm = v[i].first;
      }
    }
    return count;
  }
};