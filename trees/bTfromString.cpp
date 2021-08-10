#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

class Node
{
public:
  int val;
  Node *left = NULL;
  Node *right = NULL;
};
int n;
void solve(int indx, string a, Node *curr){
  if(indx==n)
    return;
  if(a[indx]=='('){
    solve(indx+1, a, curr);
  }
  if(a[indx]==')')
    return;
  if(a[indx]!='(' && a[indx]!=')'){
    Node * newNode =new Node ();
    newNode->val = a[indx] -'0';
    if(curr->left)
      curr->right =newNode;
    else
      curr->left =newNode;
    solve(indx+1,a,newNode);
      // curr->left = solve(indx+1, a, curr);
  }
    
  
}

int main(){


  string a ="1(2)(3)";
  n =a.size();
  return 0;
}

