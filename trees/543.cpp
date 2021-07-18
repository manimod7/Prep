/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  int d;
  int rec(TreeNode *root)
  {
    if (root == NULL)
      return 0;
    int ld = rec(root->left);
    int rd = rec(root->right);
    int temp = max(ld, rd) + 1;
    int ans = max(temp, ld + rd + 1);
    d = max(d, ans);
    return temp;
  }

  int diameterOfBinaryTree(TreeNode *root)
  {
    d = 0;
    rec(root);
    return d - 1;
  }
};