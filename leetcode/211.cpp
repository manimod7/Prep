struct trieNode
{
  trieNode *next[26];
  bool isWord = false;
  trieNode()
  {
    isWord = false;

    for (int i = 0; i < 26; i++)
    {
      next[i] = NULL;
    }
  }
};

class WordDictionary
{
public:
  /** Initialize your data structure here. */
  trieNode *root;
  trieNode dummy;
  WordDictionary()
  {
    root = &dummy;
  }

  void addWord(string word)
  {
    int n = word.size();
    trieNode *curr = root;
    for (int i = 0; i < n; i++)
    {
      if (!curr->next[word[i] - 'a'])
        curr->next[word[i] - 'a'] = new trieNode;
      curr = curr->next[word[i] - 'a'];
    }
    curr->isWord = true;
  }
  bool help(string &word, int id, trieNode *root)
  {

    if (id == word.size() && root)
      return root->isWord;
    if (!root)
      return false;

    int i = 0;
    int n = word.size();
    bool temp = false;
    trieNode *curr = root;
    for (i = id; i < n; i++)
    {
      if (word[i] != '.')
      {
        if (!curr->next[word[i] - 'a'])
          return false;
        curr = curr->next[word[i] - 'a'];
      }
      else
      {
        for (int j = 0; j < 26; j++)
        {
          if (curr->next[j])
            temp = help(word, i + 1, curr->next[j]);
          if (temp)
            return true;
        }
        return false;
      }
    }
    return curr->isWord;
  }
  bool search(string word)
  {
    return help(word, 0, root);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */