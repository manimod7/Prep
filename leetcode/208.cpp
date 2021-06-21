struct trieNode
{
  trieNode *next[26];
  bool isWord;
  trieNode()
  {
    isWord = false;

    for (int i = 0; i < 26; i++)
    {
      next[i] = NULL;
    }
  }
};
class Trie
{
public:
  /** Initialize your data structure here. */
  trieNode *root;
  trieNode dummy;
  Trie()
  {
    root = &dummy;
  }

  /** Inserts a word into the trie. */
  void insert(string word)
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

  /** Returns if the word is in the trie. */
  bool search(string word)
  {
    trieNode *curr = root;
    int n = word.size();
    for (int i = 0; i < n; i++)
    {
      if (!curr->next[word[i] - 'a'])
      {
        return false;
      }
      curr = curr->next[word[i] - 'a'];
    }
    return curr->isWord;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix)
  {
    trieNode *curr = root;
    int n = prefix.size();
    for (int i = 0; i < n; i++)
    {
      if (!curr->next[prefix[i] - 'a'])
      {
        return false;
      }
      curr = curr->next[prefix[i] - 'a'];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */