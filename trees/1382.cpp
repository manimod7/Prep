#include <bits/stdc++.h>
using namespace std;
int main(){
  
  return 0;
}



  // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


// * Balancing a Binary Search Tree
class Solution
{
  vector<TreeNode *> nodes;
  void util(TreeNode *root)
  {
    if (!root)
      return;
    if (root->left)
      util(root->left);
    nodes.push_back(root);
    if (root->right)
      util(root->right);
  }
  TreeNode *construct(int l, int r)
  {
    if (l > r)
      return NULL;
    int mid = l + (r - l) / 2;
    TreeNode *node = nodes[mid];
    node->left = construct(l, mid - 1), node->right = construct(mid + 1, r);
    return node;
  }

public:
  TreeNode *balanceBST(TreeNode *root)
  {
    util(root);
    return construct(0, nodes.size() - 1);
  }
};