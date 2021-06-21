#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    int col1 = 0, col2 = 0,temp=0;
    cin >> col1;
    cin >> col2;
    int sum1=0, sum2=0;
    for (int i = 0; i < col1; i++)
    {
      cin >> temp;
      sum1 += temp;
    }
    temp = 0;
    cout<<"Sum 1 is "<<sum1<<endl;
    for (int i = 0; i < col2; i++)
    {
      
      cin >> temp;
      sum2 += temp;
    }
    temp=0;
    cout<<"Sum2 is "<<sum2<<endl;
    if (sum1 > sum2)
      cout << "C1\n";
    else
      cout << "C2\n";
  }
  return 0;
}