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
  vector<vector<int>> ans;
  void solve(TreeNode *root, vector<int> curr, int target)
  {
    if (!root)
      return;
    if (!root->left && !root->right && target == root->val)
    {
      curr.push_back(root->val);
      ans.push_back(curr);
      return;
    }

    curr.push_back(root->val);
    solve(root->left, curr, target - root->val);
    solve(root->right, curr, target - root->val);
  }
  vector<vector<int>> pathSum(TreeNode *root, int targetSum)
  {
    solve(root, vector<int>(), targetSum);
    return ans;
  }
};