#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef unsigned long long int ll;

int main(){
  vector<string> v;
  queue<string> q;
  q.push("1");
  int n = 5,N=n;
  while (n--)
  {
    string s1 = q.front();
    q.pop();
    v.push_back(s1);
    q.push(s1 + "0");
    q.push(s1 + "1");
  }
  long long sum = 0;
  for(int i=0;i<N;i++){
    int temp =stoi(v[i]);
    sum+=temp;
  }
  cout<<sum;
  return 0;
}



