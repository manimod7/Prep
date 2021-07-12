class Solution
{
public:
  vector<string> topKFrequent(vector<string> &words, int k)
  {
    vector<string> ans;
    unordered_map<string, int> freq;
    for (auto w : words)
    {
      freq[w]++;
    }

    auto comp = [&](const pair<string, int> &a, const pair<string, int> &b)
    {
      return a.second < b.second || (a.second == b.second && a.first > b.first);
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(freq.begin(), freq.end(), comp);
    while (k--)
    {
      ans.push_back(pq.top().first);
      pq.pop();
    }
    return ans;
  }
};