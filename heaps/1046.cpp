class Solution
{
public:
  int lastStoneWeight(vector<int> &st)
  {
    priority_queue<int> q(st.begin(), st.end());
    while (q.size() > 1)
    {
      auto a = q.top();
      q.pop();
      auto b = q.top();
      q.pop();
      if (a - b > 0)
        q.push(a - b);
    }
    return q.empty() ? 0 : q.top();
  }
};