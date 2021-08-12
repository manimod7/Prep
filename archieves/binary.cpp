#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n ;
  cin>>n;
  //1 10 11 100 101
  queue<string> q;
  q.push("1");
  vector<string> ans;
  int m =n;
  while(n--){
    string top = q.front();
    q.pop();
    ans.push_back(top);
    string str1 = top+"0";
    string str2 = top+"1";
    q.push(str1);
    q.push(str2);
  }
  int res=0;
  for(int i=0;i<ans.size();i++)
    res = res+ stoi(ans[i]);
  cout<<res;
  return 0;
}