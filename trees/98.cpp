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
  long long int max(long long int a, long long int b)
  {
    return (a >= b) ? a : b;
  }
  long long int min(long long int a, long long int b)
  {
    return (a <= b) ? a : b;
  }
  long long int leftMax(TreeNode *root)
  {
    if (!root)
      return LLONG_MIN;
    return max(root->val, max(leftMax(root->left), leftMax(root->right)));
  }

  long long int rightMin(TreeNode *root)
  {
    if (!root)
      return LLONG_MAX;
    return min(root->val, min(rightMin(root->left), rightMin(root->right)));
  }
  bool solve(TreeNode *root)
  {
    if (!root)
      return true;
    long long int left = leftMax(root->left);
    long long int right = rightMin(root->right);
    return (left < root->val && right > root->val && solve(root->left) && solve(root->right));
  }
  bool isValidBST(TreeNode *root)
  {
    return solve(root);
  }
};