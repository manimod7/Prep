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
  int flag = 0, ans;
  int h;
  void left(TreeNode *root, int H)
  {
    if (!root)
      return;
    if (H == h && flag == 0)
    {
      ans = root->val;
      flag = 1;
      return;
    }
    left(root->left, H + 1);
    left(root->right, H + 1);
  }
  int height(TreeNode *root)
  {
    if (!root)
      return 0;
    return 1 + max(height(root->left), height(root->right));
  }
  int findBottomLeftValue(TreeNode *root)
  {
    h = height(root);
    //cout<<h;
    left(root, 1);

    return ans;
  }
};