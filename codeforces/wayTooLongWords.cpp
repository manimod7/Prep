#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt","w",stdout);
  #endif

  int n;
  cin>>n;
  vector<string> s;
  for(int i=0;i<n;i++){
    string temp ;
    cin>>temp;
    s.push_back(temp);
  }
  for(int i=0;i<n;i++)
{ 
  int size =s[i].size();
  if(size>10){
    string a;
    a+= s[i][0];
    a= a+to_string(size-2);
    a+=s[i][size-1];
    cout<<a<<endl;
  }
  else
    cout<<s[i]<<endl;
  
}

  return 0;
}
