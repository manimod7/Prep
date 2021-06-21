class Solution
{
public:
  /*
        Used 3 binary searches
    */
  int findInMountainArray(int target, MountainArray &mountainArr)
  {

    int n = mountainArr.length();

    int lo = 0, hi = n - 1, mid;
    bool found = false;

    /*
            finding the mountain peak first using binary search
            F*T*, last F is the mountain
        */
    while (lo < hi)
    {
      mid = lo + (hi - lo + 1) / 2;
      if (mountainArr.get(mid) - mountainArr.get(mid - 1) < 0)
        hi = mid - 1;
      else
        lo = mid;
    }

    //now mountain is at the lo index
    int peak = lo;

    /*
            binary search the left side of the peak which is in ascending order
            F*T*, first T is target
        */
    lo = 0, hi = peak;
    while (lo < hi)
    {
      mid = lo + (hi - lo) / 2;
      if (mountainArr.get(mid) < target)
        lo = mid + 1;
      else
        hi = mid;
    }

    if (mountainArr.get(lo) == target)
      return lo;

    cout << mid << endl;
    /*
            binary search the right side of the peak which is in descending order
            F*T*, first T is target
        */
    lo = peak, hi = n - 1;
    while (lo < hi)
    {
      mid = lo + (hi - lo) / 2;
      if (mountainArr.get(mid) > target)
        lo = mid + 1;
      else
        hi = mid;
    }

    if (mountainArr.get(lo) == target)
      return lo;

    //if element is not found
    return -1;
  }
};