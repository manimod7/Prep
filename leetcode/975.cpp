#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> arr{2,3,1,1,4};
  int n = arr.size();
  map<int, pair<bool, bool>> m;
  for (int i = 0; i < n - 1; i++)
  {
    m[i] = {false, false};
  }
  
  m[n - 1] = {true, true};
  for (int i = n - 2; i >= 0; i--)
  { 
    int mn = INT_MIN, mx = INT_MAX;
    for (int j = i+1; j < n; j++)
    {
      if (arr[j] >= arr[i])
      {
        if (mx > arr[j])
        {
          mx = arr[j];
          m[i].first = m[j].second;
        }
      }
      if (arr[j] <= arr[i])
      {
        if (mn < arr[j])
        {
          mn = arr[j];
          m[i].second = m[j].first;
        }
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (m[i].first == true)
      cnt++;
  }
  return 0;
}
