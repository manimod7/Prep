#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int findJudge(int n, vector<vector<int>> &trust)
{
  unordered_map<int, int> mp;
  int maxIndex = 0;
  for (int i = 0; i < trust.size(); i++)
  {
    mp[trust[i][1]]++;
    if (mp[trust[i][1]] >= mp[maxIndex])
      maxIndex = trust[i][1];
  }
  for (int i = 0; i < trust.size(); i++)
    if (trust[i][0] == maxIndex)
      return -1;
  return maxIndex;
}

int main(){

vector<vector<int>> trust{{1,3}, {2,3}};
findJudge(3, trust);

  return 0;
}
