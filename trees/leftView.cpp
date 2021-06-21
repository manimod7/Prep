vector<int> leftView(Node *root)
{
  // Your code here
  map<int, int> mp;
  queue<pair<Node *, int>> q;
  vector<int> ans;
  if (!root)
    return ans;
  q.push({root, 0});
  mp[0] = root->data;

  while (!q.empty())
  {
    Node *curr = q.front().first;
    int h = q.front().second;
    q.pop();
    if (!mp[h])
      mp[h] = curr->data;
    if (curr->left)
      q.push({curr->left, h + 1});
    if (curr->right)
      q.push({curr->right, h + 1});
  }
  for (auto i : mp)
  {
    ans.push_back(i.second);
  }
  return ans;
}