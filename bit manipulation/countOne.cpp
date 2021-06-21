#include <bits/stdc++.h>
#include<bitset>
using namespace std;
int main(){
  int a =5;
  string b = bitset<32>(a).to_string();
  cout<<b;
  return 0;
}
