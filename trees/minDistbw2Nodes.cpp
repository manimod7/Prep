unordered_map<int, int> mp;
void height(Node *root, int x, int depth)
{
  if (!root)
    return;
  if (root->data == x)
  {
    mp[x] = depth;
    return;
  }

  height(root->left, x, depth + 1);
  height(root->right, x, depth + 1);
}
Node *solve(Node *root, int n1, int n2)
{
  if (!root)
    return root;
  if (root->data == n1 || root->data == n2)
    return root;
  Node *left = solve(root->left, n1, n2);
  Node *right = solve(root->right, n1, n2);
  if (!left)
    return right;
  if (!right)
    return left;
  return root;
}
int findDist(Node *root, int a, int b)
{
  // Your code here
  height(root, a, 0);
  height(root, b, 0);
  Node *lcaNode = solve(root, a, b);
  int lca = lcaNode->data;
  height(root, lca, 0);
  return mp[a] + mp[b] - 2 * mp[lca];
}