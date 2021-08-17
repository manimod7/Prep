// //Next Greater Element 2

// class Solution
// {
// public:
//   vector<int> nextGreaterElements(vector<int> &A)
//   {
//     int n = A.size();
//     vector<int> stack, res(n, -1);
//     for (int i = 0; i < n * 2; ++i)
//     {
//       while (stack.size() && A[stack.back()] < A[i % n])
//       {
//         res[stack.back()] = A[i % n];
//         stack.pop_back();
//       }
//       stack.push_back(i % n);
//     }
//     return res;
//   }
// };

#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> A { 1, 2, 3, 4, 3 };
  int n = A.size();
  vector<int> stack, res(n, -1);
  for (int i = 0; i < n * 2; ++i)
  {
    while (stack.size() && A[stack.back()] < A[i % n])
    {
      res[stack.back()] = A[i % n];
      stack.pop_back();
    }
    stack.push_back(i % n);
  }
  return 0;
}