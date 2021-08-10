class Solution
{
public:
  char nextGreatestLetter(vector<char> &letters, char target)
  {
    int n = letters.size();
    if (target >= letters[n - 1])
      return letters[0];
    int left = 0, right = n - 1, mid;
    while (left < right)
    {
      mid = (left + right) / 2;
      if (target >= letters[mid])
        left = mid + 1;
      else
        right = mid;
    }
    return letters[left];
  }
};