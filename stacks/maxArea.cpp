#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> height {2,1,5,6,2,3};
  stack<int> s;
  height.push_back(0);
  int maxSize = 0;
  for (int i = 0; i < height.size(); i++)
  {
    if (s.empty() || height[i] >= height[s.top()])
    {
      s.push(i);
    }
    else
    {
      int temp = height[s.top()];
      s.pop();
      maxSize = max(maxSize, temp * (s.empty() ? i : i - 1 - s.top()));
      i--;
    }
  }
  return 0;
}