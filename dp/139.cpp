class Solution
{
public:
  unordered_map<string, bool> mp;
  bool solve(string s, unordered_set<string> dict)
  {

    int n = s.size();
    if (dict.find(s) != dict.end())
      return mp[s] = true;
    if (mp.find(s) != mp.end())
      return mp[s];

    for (int i = 1; i <= n; i++)
    {
      string temp = s.substr(0, i);
      if (dict.find(temp) != dict.end() && solve(s.substr(i), dict))
      {
        mp[s] = true;
        return true;
      }
    }
    return mp[s] = false;
  }
  bool wordBreak(string s, vector<string> &wordDict)
  {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    return solve(s, dict);
  }
};