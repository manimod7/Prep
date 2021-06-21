#include <bits/stdc++.h>
using namespace std;
int main(){
  
  return 0;
};


class Solution{
  public:
    string longestPalindrome(string s){
      int n=s.size(), c,l,r, maxLength =1,maxC=0;
      for(c=0;c<n;c++){
        //Enumerate the odd length palindromes with c as center
        l =c-1, r=c+1;
        while(l>=0 && r<n && s[l]==s[r]){
          //maxLength =max(maxLength,r-l+1);
          l--;r++;
        }
        if(maxLength<r-l-1){
          maxLength = r - l - 1;
          maxC =c;
        }
        //Enumerate the even length palindrome with c as center
        //c is the left center
        if(c+1<n && s[c+1]==s[c]){
          l=c-1, r=c+2;
          while(l>=0 && r<n && s[l]==s[r]){
            l--; r++;
          }
          if (maxLength < r - l - 1){
            maxLength = r - l - 1;
            maxC = c;
          }
        }
      }
      return s.substr(maxC-((maxLength-1)/2), maxLength);
    }
};