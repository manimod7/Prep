#include<bits/stdc++.h>
using namespace std;
int main(){
  int n =4;
  vector<vector<int>> a(n,vector<int> (n, false));

  int m =n;
  int k=0, l=0;
  int val = 1;

  while(k<m && l<n){
      for(int i=l;i<n;i++){
        a[k][i] =val++;
      }
      k++;
      for(int i=k;i<m;i++){
        a[i][n-1] = val++;
      }
      n--;
      if(k<m){
        for(int i=n-1;i>=l;i--){
          a[m-1][i] = val++;
        }
        m--;
      }
      if(l<n){
        for(int i=m-1;i>=k;i--){
          a[i][l] = val++;
        }
        l++;
      }
  }
  
  return 0;
}