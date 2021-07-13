#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &height)
{
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
  return maxSize;
  }


int main(){
  vector<int> h {1,2,3,4,5,6};
  largestRectangleArea(h);
  return 0;
}
