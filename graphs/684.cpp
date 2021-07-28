class Solution
{
public:
  int find(vector<int> &parent, int node)
  {
    if (parent[node] == -1)
      return node;
    return parent[node] = find(parent, parent[node]);
  }

  void _union(vector<int> &parent, int from, int to)
  {
    int fromP = find(parent, from);
    int toP = find(parent, to);
    parent[fromP] = toP;
  }

  vector<int> findRedundantConnection(vector<vector<int>> &e /*dges*/)
  {

    vector<int> parent(e.size() + 1, -1);

    for (int i = 0; i < e.size(); ++i)
    {
      int from = e[i][0], to = e[i][1];
      int fromP = find(parent, from), toP = find(parent, to);
      if (fromP == toP)
        return {from, to};
      _union(parent, from, to);
    }

    /* No redundant edge found */
    return vector<int>();
  }
};