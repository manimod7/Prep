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


  return 0;
}

class Solution
{
public:
  unordered_set<string> dict;
  unordered_map<string, vector<string>> mp;
  vector<string> solve(string s)
  {
    int n = s.size();
    vector<string> res;
    if (mp.find(s) != mp.end())
      return mp[s];
    if (dict.find(s) != dict.end())
      {
        res.push_back(s);
      }
    for (int i = 1; i <= n; i++)
    {
      string left = s.substr(0, i);
      if (dict.find(left) != dict.end())
      {
        vector<string> subRes = solve(s.substr(i));
        for (auto it : subRes)
        {
          res.push_back(left + " " + it);
        }
      }
    }
    mp[s] = res;
    return res;
  }
  vector<string> wordBreak(string s, vector<string> &wordDict)
  {
    for (int i = 0; i < wordDict.size(); i++)
    {
      dict.insert(wordDict[i]);
    }
    vector<string> ans = solve(s);
    return ans;
  }
};