class Solution
{
public:
  int guessNumber(int n)
  {
    //simple binary search : low = 1; high = n
    int low = 1;
    while (low <= n)
    {
      int mid = (low + n) / 2;
      int res = guess(mid);
      if (res == 0)
        return mid;
      else if (res == -1)
        n = mid - 1;
      else
        low = mid + 1;
    }
    return -1;
  }
};