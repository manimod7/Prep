class Solution
{
public:
  int sum = 0;
  TreeNode *convertBST(TreeNode *root)
  {

    Rinorder(root);
    return root;
  }

  void Rinorder(TreeNode *root)
  {
    if (root == NULL)
      return;
    Rinorder(root->right);

    sum += root->val;
    root->val = sum;

    Rinorder(root->left);
  }
};