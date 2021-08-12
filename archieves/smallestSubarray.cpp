#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int k;
  cin>>k;
  int arr[n];
  int totalSum = 0;
  for(int i=0;i<n;i++){
    cin >> arr[i];
    totalSum+=arr[i];
  }
    int ans =INT_MAX;
  for(int i=0;i<n;i++){
    int sum =0;
    for(int j=i;j<n;j++){
      sum+=arr[j];
      if(sum%k==totalSum%k){
        ans=min(ans,j-i+1);
        break;
      }
    }
  }
  if(ans==INT_MAX)
    cout<<"Not Possible\n";
  else
    cout<<ans;
  
  return 0;
}