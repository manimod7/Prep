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
  TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int start, int end)
  {
    if (start > end)
      return NULL;
    TreeNode *res = new TreeNode(preorder[idx++]);
    // if (start == end)
    //   return res;
    int mid = mp[res->val];
    res->left = solve(preorder, inorder, start, mid - 1);
    res->right = solve(preorder, inorder, mid + 1, end);
    return res;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    int n = inorder.size();
    for (int i = 0; i < n; i++)
      mp[inorder[i]] = i;
    return solve(preorder, inorder, 0, n - 1);
  }
};