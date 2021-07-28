#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;
int N;
void inOrder(vector<int> &in, int curr, vector<int> &arr) {
  if(curr>=N)
    return;
  if(arr[curr]==-1)
    return;
  if(2*curr+1<N){
    inOrder(in, 2*curr+1, arr);
  }
  in.push_back(arr[curr]);
  if(2*curr+2<N)
    inOrder(in, 2*curr+2, arr);
}
int main(){

  int n;
  cin>>n;
  N=n;
  vector<int> arr(n,0);

  for(int i=0;i<n;i++){
    cin>> arr[i];
  }

  int cntone=0;
  for(int i=0;i<n;i++){
    if(arr[i]==-1)
    cntone++;
  }

  vector<int> in;
  inOrder(in, 0 ,arr);

  vector<int> ans(n-cntone,0);
  for(int i=0;i<n-cntone;i++){
    if(i==0){
      ans[0]=in[1];
    }
    else if(i==n-cntone-1){
      ans[i] =in[n-cntone-2];
    }
    else{
      ans[i]=in[i-1]+in[i+1];
    }
  }
  for(int i=0;i<ans.size()-1;i++){
    cout<<ans[i]<<" ";
  }
  cout<<ans[ans.size()-1];
  return 0;
}
