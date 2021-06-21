vector<int> diagonal(Node *root)
{
  // your code here
  vector<int> ans;
  queue<Node *> q;
  if (!root)
    return ans;
  q.push(root);
  while (!q.empty())
  {
    Node *curr = q.front();
    q.pop();
    while (curr)
    {
      if (curr->left)
        q.push(curr->left);
      ans.push_back(curr->data);
      curr = curr->right;
    }
  }
  return ans;
}