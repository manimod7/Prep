class Solution
{
public:
  //Top Down
  unordered_map<string, bool> mp;
  unordered_set<string> dict;
  bool solve(string s)
  {
    int n = s.size();
    if (dict.find(s) != dict.end())
      return true;
    if (mp.find(s) != mp.end())
      return mp[s];
    for (int i = 1; i <= n; i++)
    {
      string left = s.substr(0, i);
      if (dict.find(left) != dict.end() && solve(s.substr(i)))
      {
        mp[s] = true;
        return true;
      }
    }
    mp[s] = false;
    return false;
  }
  bool wordBreak(string s, vector<string> &wordDict)
  {

    for (int i = 0; i < wordDict.size(); i++)
    {
      dict.insert(wordDict[i]);
    }
    return solve(s);
  }
};