// C++ program to find the
// sum of subarray whose sum is
// closest to K
#include <bits/stdc++.h>
using namespace std;

// Function to find the sum of subarray
// whose sum is closest to K
int closestSubarraySumToK(int a[], int n, int k)
{

  // Declare a set
  set<int> s;

  // initially consider the
  // first subarray as the first
  // element in the array
  int presum = a[0];

  // insert
  s.insert(a[0]);

  // Initially let this difference
  // be the minimum
  int mini = abs(a[0] - k);

  // let this be the sum
  // of the subarray
  // to be searched initially
  int sum = presum;

  // iterate for all the array elements
  for (int i = 1; i < n; i++)
  {

    // calculate the prefix sum
    presum += a[i];

    // find the closest subarray
    // sum to by using lower_bound
    auto it = s.lower_bound(presum - k);

    // if it is the first element
    // in the set
    if (it == s.begin())
    {

      // get the prefix sum till start
      // of the subarray
      int diff = *it;

      // if the subarray sum is closest to K
      // than the previous one
      if (abs((presum - diff) - k) < mini)
      {

        // update the minimal difference
        mini = abs((presum - diff) - k);

        // update the sum
        sum = presum - diff;
      }
    }

    // if the difference is
    // present in between
    else if (it != s.end())
    {

      // get the prefix sum till start
      // of the subarray
      int diff = *it;

      // if the subarray sum is closest to K
      // than the previous one
      if (abs((presum - diff) - k) < mini)
      {

        // update the minimal difference
        mini = abs((presum - diff) - k);

        // update the sum
        sum = presum - diff;
      }

      // also check for the one before that
      // since the sum can be greater than
      // or less than K also
      it--;

      // get the prefix sum till start
      // of the subarray
      diff = *it;

      // if the subarray sum is closest to K
      // than the previous one
      if (abs((presum - diff) - k) < mini)
      {

        // update the minimal difference
        mini = abs((presum - diff) - k);

        // update the sum
        sum = presum - diff;
      }
    }

    // if there exists no such prefix sum
    // then the current prefix sum is
    // checked and updated
    else
    {

      // if the subarray sum is closest to K
      // than the previous one
      if (abs(presum - k) < mini)
      {

        // update the minimal difference
        mini = abs(presum - k);

        // update the sum
        sum = presum;
      }
    }

    // insert the current prefix sum
    s.insert(presum);
  }

  return sum;
}

// Driver Code
int main()
{
  int a[] = {-5, 12, -3, 4, -15, 6, 1};
  int n = sizeof(a) / sizeof(a[0]);
  int k = 2;

  cout << closestSubarraySumToK(a, n, k);
  return 0;
}
