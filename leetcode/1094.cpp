#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
  return a[1] <= b[1];
}

bool carPooling(vector<vector<int>> &trips, int capacity)
{
  sort(trips.begin(), trips.end(), [](vector<int> a, vector<int> b)
      { return a[1] <= b[1]; });
  int currCapacity = 0;
  map<int, int> mp;
  for (int i = 0; i < trips.size(); i++)
  {
    mp[trips[i][2]] += trips[i][0];
  }
  for (int i = 0; i < trips.size(); i++)
  {
    currCapacity += trips[i][0];
    if (mp.find(trips[i][1]) != mp.end())
      currCapacity -= mp[trips[i][1]];
    if (currCapacity > capacity)
      return false;
  }
  return true;
}
  int main()
  {
    vector<vector<int>> trips {{2,1,5},{3,3,7}};
    int c =4;
    carPooling(trips,c);
    return 0;
  }
