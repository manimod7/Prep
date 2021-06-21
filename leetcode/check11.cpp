#include <bits/stdc++.h>
using namespace std;
int main(){
  string a ="abcd";
  int end =a.size()-1;
  for(int i=0;i<=end;i++){
    string temp =a.substr(i,end-i+1);
    cout<<temp<<" ";
  }
  return 0;
}
