class Solution
{
public:
  void dfs(vector<vector<int>> &graph_red, vector<vector<int>> &graph_blue, bool redFlag, int v, vector<vector<int>> &ans, int curr_dist)
  {
    if (redFlag && ans[v][0] < curr_dist)
    {
      return;
    }
    if (!redFlag && ans[v][1] < curr_dist)
    {
      return;
    }
    if (redFlag)
      ans[v][0] = min(ans[v][0], curr_dist);
    else
      ans[v][1] = min(ans[v][1], curr_dist);
    if (redFlag)
    {
      for (auto x : graph_red[v])
        dfs(graph_red, graph_blue, !redFlag, x, ans, curr_dist + 1);
    }
    else
    {
      for (auto x : graph_blue[v])
        dfs(graph_red, graph_blue, !redFlag, x, ans, curr_dist + 1);
    }
  }
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges)
  {
    vector<vector<int>> graph_red(n, vector<int>());
    vector<vector<int>> graph_blue(n, vector<int>());
    for (auto x : red_edges)
      graph_red[x[0]].push_back(x[1]);

    for (auto x : blue_edges)
      graph_blue[x[0]].push_back(x[1]);

    vector<vector<int>> ans(n, {INT_MAX, INT_MAX});
    ans[0][0] = 0, ans[0][1] = 0;
    bool red_flag = true;
    for (auto x : graph_red[0])
    {
      dfs(graph_red, graph_blue, !red_flag, x, ans, 1);
    }
    for (auto x : graph_blue[0])
    {
      dfs(graph_red, graph_blue, red_flag, x, ans, 1);
    }
    for (int i = 0; i < n; i++)
    {
      ans[i][0] = min(ans[i][0], ans[i][1]);
      if (ans[i][0] == INT_MAX)
        ans[i][0] = -1;
    }
    vector<int> retVal(n);
    for (int i = 0; i < n; i++)
    {
      retVal[i] = ans[i][0];
    }
    return retVal;
  }
};