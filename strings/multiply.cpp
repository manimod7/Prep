#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int main(){

  ios_base::sync_with_stdio(false);
  string s1="1234", s2="5678";
  int l1=s1.size(), l2 =s2.size();
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  //string s3;
  string s3(l1+l2,'0');

  for(int i=0;i<l1;i++){
    for(int j=0;j<l2;j++){
      int temp =s3[i+j] -'0' +(int) (s1[i]-'0')*(int)(s2[j]-'0');
      s3[i+j] = (char) temp%10 +'0';
      s3[i+j+1]+= (char) temp/10;
    }
  }
  for (int i = l1 + l2 - 1; i > 0 && s3[i] == '0'; i--)
    s3.pop_back();
  reverse(s3.begin(), s3.end());
  cout<<s3;


  return 0;
}
