#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int> arr(n,0);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  // n = 4
  //2 2 2 2   -> 0

  // n = 5
  // 3 1 0 1 3  -> 7

  //n = 6
  // 4 5 2 6 2 1  ->3

  //n = 6
  // 2 3 2 2 3 2
  vector<int> left(n,0);

  vector<int> right(n,0);

  for(int i=1;i<n;i++){
    left[i] = max(left[i-1], arr[i-1]);
  }
  //left[0] = arr[0];
  for(int i=n-2;i>=0;i--){
    right[i] = max(right[i+1], arr[i+1]);
  }
  //right[n-1] = arr[n-1];
  int trap = 0;
  for(int i=0;i<n;i++){
    int temp = min(left[i], right[i]);
    if(arr[i]>temp)
      continue;
    else
      trap+= temp - arr[i];
  }
  cout<< trap;
  return 0;
}