/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
  TreeNode *cloneAns = NULL;
  void solve(TreeNode *original, TreeNode *cloned, TreeNode *target)
  {
    if (!original || !cloned)
      return;
    if (target == original)
    {
      cloneAns = cloned;
      return;
    }
    solve(original->left, cloned->left, target);
    solve(original->right, cloned->right, target);
  }
  TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
  {
    if (!target || !original || !cloned)
      return NULL;

    solve(original, cloned, target);
    return cloneAns;
  }
};