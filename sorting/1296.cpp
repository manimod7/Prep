class Solution
{
public:
  bool isPossibleDivide(vector<int> &nums, int k)
  {
    std::map<int, int> m;
    for (auto num : nums)
      m[num]++;

    for (auto [key, value] : m)
    {
      while (m[key])
      {
        for (int i = key; i < key + k; ++i)
        {
          m[i]--;
          if (m[i] < 0)
            return false;
        }
      }
    }
    return true;
  }
};
// m[1] =1 / 0
// m[2] =1 / 0
// m[3] =2 /1
// m[4] =2 /1
// m[5] =1
// m[6] =1
//1 2 3 3 4