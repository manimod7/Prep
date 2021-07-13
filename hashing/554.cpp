class Solution
{
public:
  int leastBricks(vector<vector<int>> &wall)
  {
    unordered_map<int, int> hash;
    int edge = 0, max = 0;
    for (int i = 0; i < wall[0].size(); i++)
    {
      edge += wall[0][i];
    }
    for (int i = 0; i < wall.size(); i++)
    {
      int tempsum = 0;
      for (int j = 0; j < wall[i].size(); j++)
      {
        tempsum += wall[i][j];
        if (tempsum != edge)
          hash[tempsum]++;
      }
    }

    for (auto x : hash)
    {
      if (x.second > max)
        max = x.second;
    }
    return wall.size() - max;
  }
};