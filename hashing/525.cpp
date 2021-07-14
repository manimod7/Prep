int findMaxLength(vector<int> &nums)
{
  int sum = 0;
  unordered_map<int, int> m;
  unsigned int longestContArray = 0;

  for (int i = 0; i < nums.size(); i++)
  {
    sum += (nums[i] == 0) ? -1 : 1;

    auto it = m.find(sum);

    if (sum == 0)
    {
      if (longestContArray < i + 1)
        longestContArray = i + 1;
    }
    else if (it != m.end())
    {
      if (longestContArray < i - it->second)
        longestContArray = i - it->second;
    }
    else if (it == m.end())
      m.insert({sum, i});
  }
  return longestContArray;
}

//1 1 1 1 -1 -1 -1 -1
/* 
  m[1] = 0
  m[2] = 1
  m[3] = 2
  m[4] = 3
  * m[3] = 4 but m[3] already exist so we dont update m[3],
  * instead we take maLength = i -m[3] =4-2 =2

*/