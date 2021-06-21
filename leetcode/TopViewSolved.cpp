class Solution
{
public:
  //2 1 7 9 17 23 16 22 42 63 64
  map<int, map<int, vector<int>>> mp;
  //Function to return a list of nodes visible from the top view
  //from left to right in Binary Tree.
  void solve(Node *root, int x, int y)
  {
    if (!root)
      return;

    auto &it = mp[x];
    it[y].push_back(root->data);
    solve(root->left, x - 1, y + 1);
    solve(root->right, x + 1, y + 1);
  }
  vector<int> topView(Node *root)
  {
    //Your code here
    vector<int> ans;
    solve(root, 0, 0);
    for (auto i : mp)
    {
      auto j = i.second.begin();
      auto temp = j->second;
      ans.push_back(temp[0]);
    }
    return ans;
  }
};