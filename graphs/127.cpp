//Word Ladder
class Solution
{
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {

    unordered_set<string> dict(wordList.begin(), wordList.end());
    unordered_set<string> visited;
    string currWord = beginWord, tempWord = beginWord;
    int currDist = 0, n = beginWord.size();
    if (currWord == endWord)
      return 1;
    queue<pair<string, int>> q;
    q.push({currWord, 1});

    while (!q.empty())
    {
      auto x = q.front();
      q.pop();
      currWord = x.first;
      currDist = x.second;
      if (currWord == endWord)
        return currDist;
      tempWord = currWord;
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < 26; j++)
        {
          tempWord[i] = (char)j + 'a';
          if (dict.find(tempWord) != dict.end() && visited.find(tempWord) == visited.end())
          {
            q.push({tempWord, currDist + 1});
            visited.insert(tempWord);
          }
        }
        tempWord[i] = currWord[i];
      }
    }
    return 0;
  }
};