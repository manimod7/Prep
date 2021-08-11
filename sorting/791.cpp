#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;
string order1;
bool cmp(char a, char b)
  {
    return order1.find(a) < order1.find(b); 
  }
string customSortString(string order, string str)
{
  sort(str.begin(), str.end(), cmp);
  return str;
}
int main(){

string  order ="dabc";
order1=order;
string toSort = "abcabcabd";
string ans = customSortString(order,toSort);
cout<<ans;


  return 0;
}


