#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t, n;
  cin >> t;
  int t1=t;
  int ans[t];
  int i=0;
  while (t--)
  {
    int ans1 = 0;
    cin >> n;
    ans1 = n / 2;
    if (n % 2 == 1)
      ans1++;

  ans[i++]=ans1;
  }
  for(int i=0;i<t1;i++){
    cout<<ans[i]<<endl;
  }
  return 0;
}
