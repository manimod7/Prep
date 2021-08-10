class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    unordered_map<char, int> mp;
    int n = s.size();
    // if(n==0)
    //     return 0;
    int i = 0, j = 0;
    int maxLen = 0;
    //mp[s[j]]=1;
    while (mp[s[j]] == 0 && j < n)
    {
      mp[s[j]]++;
      maxLen = j - i + 1;
      j++;
    }

    while (j < n)
    {
      if (mp[s[j]] > 0)
      {
        mp[s[i]]--;
        i++;
      }
      else
      {
        mp[s[j]]++;
        maxLen = max(maxLen, j - i + 1);
        j++;
      }
    }
    return maxLen;
  }
};