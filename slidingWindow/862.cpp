#include <bits/stdc++.h>
using namespace std;
int main(){

  vector<int> A{1,2,3,-1,5,4,-5};
  int K =10;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  int sum = 0;
  int ans = INT_MAX;
  for (int i = 0; i < A.size(); i++)
  {
    sum += A[i];
    if (sum >= K)
    {
      ans = min(ans, i + 1);
    }
    while (pq.size() && sum - pq.top().first >= K)
    {
      auto &p = pq.top();
      ans = min(ans, i - p.second);
      pq.pop();
    }
    pq.push({sum, i});
  }
  int anS = ans == INT_MAX ? -1 : ans;
  cout<<anS<<endl;
  return 0;
}
