class Solution
{
public:
  int finish;
  unordered_set<int> st;
  map<pair<int, int>, bool> umap;
  bool solve(int start, int jumpSize)
  {
    if (umap.find({start, jumpSize}) != umap.end())
      return umap[{start, jumpSize}];
    if (jumpSize <= 0)
      return false;
    if (start == finish)
      return umap[{start, jumpSize}] = true;
    if (st.find(start) == st.end())
      return umap[{start, jumpSize}] = false;

    int newIndex = start + jumpSize;
    return umap[{start, jumpSize}] =  solve(newIndex, jumpSize - 1) ||
                                      solve(newIndex, jumpSize) ||
                                      solve(newIndex, jumpSize + 1);
  }
  bool canCross(vector<int> &stones)
  {
    int n = stones.size();
    finish = stones[n - 1];

    for (int i = 0; i < n; i++)
    {
      st.insert(stones[i]);
    }
    return solve(0, 1);
  }
};