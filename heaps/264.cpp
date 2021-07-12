class Solution
{
public:
  int nthUglyNumber(int n)
  {
    unordered_map<long long int, int> visited;
    priority_queue<long long int, vector<long long int>, greater<long long int>> q;
    int cnt = 0, temp;
    q.push(1);
    visited[1] = 1;
    while (!q.empty())
    {
      temp = q.top();
      q.pop();
      cnt++;
      if (cnt == n)
        return temp;
      if (visited.find(2L * temp) == visited.end())
      {
        q.push(2L * temp);
        visited[2L * temp] = 1;
      }
      if (visited.find(3L * temp) == visited.end())
      {
        q.push(3L * temp);
        visited[3L * temp] = 1;
      }
      if (visited.find(5L * temp) == visited.end())
      {
        q.push(5L * temp);
        visited[5L * temp] = 1;
      }
    }
    return -1;
  }
};