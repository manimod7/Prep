#include <bits/stdc++.h>
using namespace std;
map<int, map<int, vector<int>>> mp;
vector<int> ans;

//* Definition for a binary tree node.
class TreeNode
{
  public:
  int data;
  TreeNode *left = NULL;
  TreeNode *right = NULL;
  //  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  //  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  //  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void solve(TreeNode *root, int x, int y)
{
  if (!root)
    return;

  
  mp[x][y].push_back(root->data);
  solve(root->left, x - 1, y + 1);
  solve(root->right, x + 1, y + 1);
}
vector<int> topView(TreeNode *root)
{
  //Your code here
  vector<int> ans;
  solve(root, 0, 0);
  for (auto i : mp)
  {
    auto j = i.second.begin();
    vector<int> temp = j->second;
    ans.push_back(temp[0]);
  }
  return ans;
}

int main(){
  TreeNode *a = new TreeNode();
  TreeNode *b = new TreeNode();
  TreeNode *c = new TreeNode();
  TreeNode *d = new TreeNode();
  TreeNode *e = new TreeNode();
  TreeNode *f = new TreeNode();
  a->data = 1;
  b->data = 2;
  c->data = 3;
  d->data = 4;
  e->data = 6;
  a->left = b;
  a->right = c;
  c->left = d;
  c->right = e;
  topView(a);
  return 0;
}
