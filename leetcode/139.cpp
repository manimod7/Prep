//Top Down Approach
class Solution
{
public:
  bool wordBreak(string s, vector<string> &wordDict)
  {
    set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        string word = s.substr(j, i - j);
        cout << word << endl;
        if (dict.find(word) != dict.end() && dp[j])
        {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[n];
  }
};