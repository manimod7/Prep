#include <bits/stdc++.h>
using namespace std;

class MyCalendarThree
{
public:
  vector<int> s, e;
  MyCalendarThree()
  {
  }

  int book(int start, int end)
  {
    s.push_back(start);
    e.push_back(end);

    sort(s.begin(), s.end());
    sort(e.begin(), e.end());

    int n = s.size(), m = e.size();
    int k = 0, ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
      if (s[i] < e[j])
      {
        k++;
        ans = max(k, ans);
        i++;
      }
      // else if(s[i]==e[j]){
      //     j++;
      // }
      else if (e[j] <= s[i])
      {
        k--;
        ans = max(ans, k);
        j++;
      }
    }
    return ans;
  }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

int main(){
  MyCalendarThree a;
  a.book(10,20);

  return 0;
}

