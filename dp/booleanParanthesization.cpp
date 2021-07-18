class Solution
{
public:
  unordered_map<string, int> mp;
  bool solve(string s1, string s2)
  {
    int n = s1.length();
    if (s1 == s2)
      return true;
    string key = s1 + " " + s2;
    cout << key << endl;
    if (mp.find(key) != mp.end())
      return mp[key];
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
      bool unswap = solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, n - i), s2.substr(i, n - i));
      bool swapped = solve(s1.substr(0, i), s2.substr(n - i, i)) && solve(s1.substr(i, n - i), s2.substr(0, n - i));
      if (unswap || swapped)
      {
        flag = true;
        break;
      }
    }
    mp[key] = flag;
    return flag;
  }
  bool isScramble(string s1, string s2)
  {
    if (s1.length() != s2.length())
      return false;
    bool ans = solve(s1, s2);
    // for(auto i :mp){
    //     cout<<i.first<<" - ";
    //     cout<<i.second<<endl;
    // }
    return ans;
  }
};