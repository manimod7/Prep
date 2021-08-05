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
    vector<TreeNode *> v;
    void inorder(TreeNode *root)
    {
      if (!root)
        return;
      inorder(root->left);
      v.push_back(root);
      inorder(root->right);
    }
    TreeNode *constructTree(int start, int end)
    {
      if (start > end)
        return NULL;
      int mid = (start + end) / 2;
      TreeNode *root = v[mid];
      root->left = constructTree(start, mid - 1);
      root->right = constructTree(mid + 1, end);
      return root;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
      if (!root)
        return NULL;
      inorder(root);
      int n = v.size();
      return constructTree(0, n - 1);
    }
  };