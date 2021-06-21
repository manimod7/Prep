#include <bits/stdc++.h>
using namespace std;
int main(){
  
  return 0;
};

class MyCalendar
{
public:
  vector<pair<int, int>> v;

  MyCalendar()
  {
  }

  bool book(int start, int end)
  {
    for (auto x : v)
    {
      if (start < x.second && end > x.first)
        return false;
    }
    v.push_back({start, end});
    return true;
  }
};