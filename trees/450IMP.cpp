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
  TreeNode *deleteNode(TreeNode *root, int key)
  {
    if (root == NULL)
      return NULL;
    if (key < root->val)
    {
      root->left = deleteNode(root->left, key);
      return root;
    }
    else if (key > root->val)
    {
      root->right = deleteNode(root->right, key);
      return root;
    }
    else
    {
      if (root->left == NULL && root->right == NULL)
      {
        delete root;
        return NULL;
      }
      else if (root->left == NULL)
      {
        TreeNode *temp = root->right;
        root->right = NULL;
        delete root;
        return temp;
      }
      else if (root->right == NULL)
      {
        TreeNode *temp = root->left;
        root->left = NULL;
        delete root;
        return temp;
      }
      else
      {
        TreeNode *rightMin = root->right;
        while (rightMin->left != NULL)
          rightMin = rightMin->left;
        int rightMinValue = rightMin->val;
        root->val = rightMinValue;
        root->right = deleteNode(root->right, rightMinValue);
        return root;
      }
    }
  }
};