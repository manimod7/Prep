#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int maxProfit(vector<int> &prices)
{

  int n = prices.size();
  int fb = INT_MIN, sb = INT_MIN, fs = INT_MIN, ss = INT_MIN;
  //first buy    second buy    first sell    second sell

  for (int i = 0; i < n; i++)
  {
    fb = max(fb, -prices[i]);
    fs = max(fs, fb + prices[i]);
    sb = max(sb, fs - prices[i]);
    ss = max(ss, sb + prices[i]);
  }
  return ss;
}

int main(){

  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  // #ifndef ONLINE_JUDGE
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt","w",stdout);
  // #endif
  vector<int> nums {3,3,5,0,0,3,1,4};
  maxProfit(nums);

  return 0;
}
