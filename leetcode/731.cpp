#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo
{
public:
  vector<pair<int, int>> v; //pair of start and end
  MyCalendarTwo()
  {
  }

  bool book(int start, int end)
  {
    int i = 0;
    for (auto x : v)
    {
      if (start < x.second && end > x.first)
        i++;
    }
    if (i >= 2)
      return false;
    v.push_back({start, end});
    return true;
  }
};
int main(){
  MyCalendarTwo a;
  a.book(10,20);
  a.book(50,60);
  a.book(10,40);
  a.book(5,15);
  a.book(5,10);
  a.book(25,55);

  return 0;
}
