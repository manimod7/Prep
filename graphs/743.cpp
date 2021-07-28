class Solution
{
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k)
  {
    vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());

    for (auto i : times)
    {
      graph[i[0]].push_back({i[1], i[2]});
    }
    queue<pair<int, int>> q;
    vector<int> distances(n + 1, INT_MAX);
    q.push({k, 0});
    distances[k] = 0;
    while (!q.empty())
    {
      auto x = q.front();
      q.pop();
      int node = x.first;
      int dist = x.second;
      for (auto nbr : graph[node])
      {
        if (dist + nbr.second < distances[nbr.first])
        {
          distances[nbr.first] = dist + nbr.second;
          q.push({nbr.first, distances[nbr.first]});
        }
      }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
      if (distances[i] == INT_MAX)
        return -1;
      res = max(distances[i], res);
    }

    return res;
  }
};