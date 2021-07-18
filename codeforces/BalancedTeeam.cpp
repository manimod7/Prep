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
  vector<int> arr(n,0);
  for(int i=0;i<n;i++)
    cin>>arr[i];
  sort(arr.begin(), arr.end());
  int maxSize=1;
  int sum =1, ans=1;
  for (int i = 0, j = 1; j < n && i < n && i <= j;)
  {
    if (arr[j] - arr[i] <= 5)
      sum++, j++;
    else if (arr[j] - arr[i] > 5)
      i++, sum--;
    ans = max(sum, ans);
  }
  cout<<ans;

  return 0;
}
