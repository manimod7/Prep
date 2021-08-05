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
  int idx = 0;
  vector<int> ans;
  void getInorder(TreeNode *root)
  {
    if (!root)
      return;
    getInorder(root->left);
    ans.push_back(root->val);
    getInorder(root->right);
  }
  void recover(TreeNode *root)
  {
    if (!root)
      return;
    recover(root->left);
    root->val = ans[idx++];
    recover(root->right);
  }
  void recoverTree(TreeNode *root)
  {
    getInorder(root);
    sort(ans.begin(), ans.end());
    recover(root);
  }
};