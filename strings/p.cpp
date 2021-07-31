#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int main(){

  int k=3;
  
  string n ="148";
  string temp = n;
  int temp1;
  for (int i = 0; i < n.size(); i++)
  {
    temp1 += (int)n[i] - 48;
  }
  temp1 = temp1*k;
  // for (int i = 0; i < k-1; i++)
  //   n += temp;
  n = to_string(temp1);
  int sz =n.size();
  while(sz!=1){
      int size = n.size();
      int temp1 = 0;
      for (int i = 0; i < size; i++)
      {
        temp1 += (int)n[i] -48;
      }
      n = to_string(temp1);
      sz=n.size();
    }
    cout<< stoi(n);
  }

