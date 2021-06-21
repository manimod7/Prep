class Solution
{
public:
  int findCheapestPrice(int n, vector<vector<int>> &flight, int src, int dst, int k)
  {

    map<int, vector<pair<int, int>>> g;

    for (int i = 0; i < flight.size(); i++)
    {
      g[flight[i][0]].push_back({flight[i][1], flight[i][2]});
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    //tuple cost, src, stops
    vector<bool> visited(n + 1, false);
    pq.push({0, src, 0});
    while (!pq.empty())
    {
      auto [cost, u, stops] = pq.top();

      pq.pop();
      if (u == dst)
        return cost;
      if (stops > k)
        continue;
      for (auto [v, w] : g[u])
      {
        if (!visited[v])
        {
          pq.push({cost + w, v, stops + 1});
          visited[u] = true;
        }
      }
    }
    return -1;
  }
};
