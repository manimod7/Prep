class Solution
{
public:
  //Function to return a list of nodes visible from the top view
  //from left to right in Binary Tree.
  vector<int> topView(Node *root)
  {
    //Your code here
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    if (!root)
      return vector<int>();
    q.push({root, 0});
    while (!q.empty())
    {
      Node *currNode = q.front().first;
      int h = q.front().second;
      q.pop();
      if (!mp[h])
        mp[h] = currNode->data;
      if (currNode->left)
        q.push({currNode->left, h - 1});
      if (currNode->right)
        q.push({currNode->right, h + 1});
    }
    for (auto i : mp)
    {
      cout << i.second << " ";
    }
    return vector<int>();
  }
};