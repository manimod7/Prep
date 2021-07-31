class Solution
{
public:
  int N;

  vector<vector<int>> solve(int start, int end, int k)
  {
    if (k == 0)
      return {{}};

    if (start > end)
      return {};
    if (k > end - start + 1)
      return {};

    vector<vector<int>> temp1 = solve(start + 1, end, k);
    vector<vector<int>> temp2 = solve(start + 1, end, k - 1);

    for (int i = 0; i < temp2.size(); i++)
    {
      temp2[i].push_back(start);
      vector<int> t = temp2[i];
      temp1.push_back(t);
    }
    return temp1;
  }

  vector<vector<int>> combine(int n, int k)
  {
    N = n;
    return solve(1, n, k);
  }
};