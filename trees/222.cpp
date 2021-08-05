class Solution
{
public:
  int countNodes(TreeNode *root)
  {
    TreeNode *rNode = root, *lNode = root;
    int l = 0, r = 0;
    if (root == NULL)
      return 0;
    while (lNode)
    {
      l++;
      lNode = lNode->left;
    }
    while (rNode)
    {
      r++;
      rNode = rNode->right;
    }
    if (r == l)
      return pow(2, l) - 1;

    return countNodes(root->left) + countNodes(root->right) + 1;
  };
};