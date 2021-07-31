#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

vector<string> ans;
int n;
string s;
void solve(string curr, vector<bool> visited){
  if(curr.size()==n){
    ans.push_back(curr);
    return;
  }
  for(int i=0;i<n;i++){
    if(!visited[i]){
      visited[i] = true;
      curr+=s[i];
      solve(curr, visited);
      visited[i] = false;
      curr.pop_back();
    }
  }
}
int main(){

  string S;
  cin>>S;
  int N =S.size();
  n=N;
  s=S;
  vector<bool> visited(n, false);
  solve("", visited);
  
  return 0;
  
}
