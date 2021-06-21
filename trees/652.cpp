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
  unordered_map<string, int> m;
  vector<TreeNode *> res;
  string inorder(TreeNode *root)
  {
    if (!root)
      return "";

    string s = "(";
    s += inorder(root->left);
    s += to_string(root->val);
    s += inorder(root->right);
    s += ")";
    if (m[s] == 1)
      res.push_back(root);
    m[s]++;
    return s;
  }

  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
  {
    //m.clear();
    //res.clear();
    inorder(root);
    return res;
  }
};