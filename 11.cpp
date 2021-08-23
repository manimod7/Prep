#include <bits/stdc++.h>
using namespace std;
int main()
{
  vector<int> v{2, 3, 4, 5, 6, 7, 8, 9, 10};
  int low = 0;
  int high = v.size() - 1;

  while (low < high)
  {
    int mid = (low + high) / 2;
    if (v[mid] == mid + 1)
    {
      low = mid + 1;
    }
    else
      high = mid;
  }
  cout << v[low] - 1 << endl;
}

///
