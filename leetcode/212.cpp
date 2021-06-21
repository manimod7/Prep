class Solution
{
  struct Node
  {
  public:
    unordered_map<char, Node *> children;
    bool terminal = false;
    string s;
  };

  Node *root = new Node();

  void insert(string st)
  {
    Node *temp = root;
    for (char ch : st)
    {
      if (temp->children.count(ch) == 0)
      {
        temp->children[ch] = new Node();
      }
      temp = temp->children[ch];
    }
    temp->terminal = true;
    temp->s = st;
  }

  void dfs(vector<vector<char>> &board, int i, int j, int r, int c, vector<string> &ans, Node *temp)
  {
    char ch = board[i][j];
    if (board[i][j] == '$' || temp->children.count(ch) == 0)
      return;

    temp = temp->children[ch];
    if (temp->terminal)
    {
      ans.push_back(temp->s);
      temp->terminal = false;
    }

    board[i][j] = '$';
    if (i > 0)
      dfs(board, i - 1, j, r, c, ans, temp);
    if (i < r - 1)
      dfs(board, i + 1, j, r, c, ans, temp);
    if (j > 0)
      dfs(board, i, j - 1, r, c, ans, temp);
    if (j < c - 1)
      dfs(board, i, j + 1, r, c, ans, temp);

    board[i][j] = ch;
    return;
  }

public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
  {
    for (int i = 0; i < words.size(); i++)
    {
      insert(words[i]);
    }

    vector<string> ans;
    int r = board.size(), c = board[0].size();
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        dfs(board, i, j, r, c, ans, root);
      }
    }
    return ans;
  }
};