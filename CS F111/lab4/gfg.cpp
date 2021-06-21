#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  vector<int> ans;
  cin >> T;

  for (int i = 0; i < T; i++)
  {
    int count = 0;
    string a = "";
    cin >> a;
    if (a.size() <= 2)
      ans.push_back(-1);
    else
    {
      for (int j = 0; j < a.size() - 2; j++)
      {
        if (a[j] == 'g' && a[j + 1] == 'f' && a[j + 2] == 'g')
          count++;
      }
      if (count > 0)
        ans.push_back(count);
      else
        ans.push_back(-1);
    }
    
  }
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << endl;
  }
  return 0;
}