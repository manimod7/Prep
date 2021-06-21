#include <bits/stdc++.h>
using namespace std;
int main(){
  
  return 0;
}


class Solution
{
public:
  int idx = 0;
  unordered_map<int, int> mp; //map inorder array values with their indexes
  TreeNode *solve(vector<int> &postorder, vector<int> &inorder, int start, int end)
  {
    if (start > end)
      return NULL;
    TreeNode *res = new TreeNode(postorder[idx]);

    int mid = mp[postorder[idx]];
    idx--;
    res->right = solve(postorder, inorder, mid + 1, end);
    res->left = solve(postorder, inorder, start, mid - 1);

    return res;
  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    int l = 0;
    int r = inorder.size() - 1;
    idx = postorder.size() - 1;
    for (int i = 0; i < inorder.size(); i++)
    {
      mp[inorder[i]] = i;
    }
    return solve(postorder, inorder, l, r);
  }
};