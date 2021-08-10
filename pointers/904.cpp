class Solution
{
public:
  int totalFruit(vector<int> &tree)
  {
    int res = 0, curr = 0, count_b = 0, a = 0, b = 0;
    for (int c : tree)
    {
      if (c == b)
      {
        curr += 1;
        count_b++;
      }
      else if (c == a)
      {
        curr += 1;
        count_b = 1;
        a = b;
        b = c;
      }
      else
      {
        curr = count_b + 1;
        a = b;
        b = c;
        count_b = 1;
      }
      res = max(res, curr);
    }
    return res;
  }
};