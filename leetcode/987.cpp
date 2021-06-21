#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> mp;
vector<vector<int>> ans;

//* Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left = NULL;
  TreeNode *right = NULL;
  //  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  //  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  //  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void solve(TreeNode *root, int x)
{
  if (!root)
    return;
  mp[x].push_back(root->val);
  solve(root->left, x - 1);
  solve(root->right, x + 1);
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{

  for (auto i : mp)
  {
    vector<int> a = i.second;
    ans.push_back(a);
  }
  return ans;
}

int main(){
  TreeNode *a, *b,*c,*d,*e, *f, *g;
  a->val   = 1;
  b->val   = 2; 
  c->val   = 3;
  d->val   = 4;
  e->val   = 6;
  a->left  = b;
  a->right = c;
  c->left  = d;
  c->right = e;
  verticalTraversal(a);
  return 0;
}


