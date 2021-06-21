class Solution
{
public:
  bool dfs(vector<int> adj[], int x, int parent, vector<bool> &vis)
  {
    vis[x] = true;
    for (auto y : adj[x])
    {
      if (vis[y] && (parent != y || y == x))
        return true;
      else if (!vis[y] && dfs(adj, y, x, vis))
        return true;
    }
    return false;
  }

  //Function to detect cycle in an undirected graph.
  bool isCycle(int V, vector<int> adj[])
  {

    vector<bool> vis(V);
    for (int i = 0; i < V; i++)
    {
      if (!vis[i] && dfs(adj, i, -1, vis))
      {
        return true;
      }
    }
    return false;
  }
};