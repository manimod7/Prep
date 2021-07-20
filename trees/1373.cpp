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
  void solve(TreeNode *root, int &largest, int &smallest, bool &isBST, int &sum, int &maxV)
  {

    //Base Case

    if (!root)
    {
      largest = INT_MIN;
      smallest = INT_MAX;
      sum = 0;
      isBST = true;
      return;
    }

    //Recursive Step
    int leftLarge, leftSmall, leftSum, rightLarge, rightSmall, rightSum;
    bool leftBST, rightBST;

    //Get values of left subtree
    solve(root->left, leftLarge, leftSmall, leftBST, leftSum, maxV);

    //Get the values for Right Subtree
    solve(root->right, rightLarge, rightSmall, rightBST, rightSum, maxV);

    //Compute if BST or Not
    isBST = leftBST && rightBST && (root->val > leftLarge) && (root->val < rightSmall);

    sum = leftSum + rightSum + root->val;
    largest = max(root->val, max(leftLarge, rightLarge));
    smallest = min(root->val, min(leftSmall, rightSmall));

    if (isBST)
      maxV = max(maxV, sum);
  }
  int maxSumBST(TreeNode *root)
  {
    int largestVal = INT_MIN, smallestVal = INT_MAX, sum = 0, maxV = INT_MIN;
    bool isBST = false;
    solve(root, largestVal, smallestVal, isBST, sum, maxV);
    return max(0, maxV);
  }
};