int height(Node *node)
{
  /* base case tree is empty */
  if (node == NULL)
    return 0;

  /* If tree is not empty then 
    height = 1 + max of left 
        height and right heights */
  return 1 + max(height(node->left),
                 height(node->right));
}
bool isBalanced(Node *root)
{
  //  Your Code here
  if (root == NULL)
    return 1;

  /* Get the height of left and right sub trees */
  int lh = height(root->left);
  int rh = height(root->right);

  if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
    return 1;

  /* If we reach here then 
    tree is not height-balanced */
  return 0;
}