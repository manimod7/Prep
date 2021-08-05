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
  vector<int> vec;

public:
  void rec(TreeNode *p, int v)
  {
    if (p == NULL)
      return;
    v = v * 10 + p->val;
    if (p && !p->left && !p->right)
      vec.push_back(v);
    rec(p->left, v);
    rec(p->right, v);
  }
  int sumNumbers(TreeNode *root)
  {
    int v = 0, sum = 0;
    rec(root, v);
    for (int i = 0; i < vec.size(); i++)
    {
      sum += vec[i];
    }
    return sum;
  }
};