class Solution
{
public:
  void leftTree(Node *root, vector<int> &ans)
  {
    if (!root)
      return;
    if (root->left)
    {
      ans.push_back(root->data);
      leftTree(root->left, ans);
    }
    else if (root->right)
    {
      ans.push_back(root->data);
      leftTree(root->right, ans);
    }
  }

  void Leaf(Node *root, vector<int> &ans)
  {
    if (!root)
      return;
    Leaf(root->left, ans);
    if (!root->left && !root->right)
      ans.push_back(root->data);
    Leaf(root->right, ans);
  }

  void rightTree(Node *root, vector<int> &ans)
  {
    if (!root)
      return;
    if (root->right)
    {
      rightTree(root->right, ans);
      ans.push_back(root->data);
    }
    else if (root->left)
    {
      rightTree(root->left, ans);
      ans.push_back(root->data);
    }
  }

  vector<int> printBoundary(Node *root)
  {
    //Your code here
    vector<int> ans;
    ans.push_back(root->data);
    leftTree(root->left, ans);
    Leaf(root, ans);
    rightTree(root->right, ans);
    return ans;
  }
};
