#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<vector<char>> board {
    {'a','b','c','d'}, {'e','f','g','h'}, {'i','j','k','l'}, {'m','n','o','p'}};
    string a ;
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        a+=(char) board[i][j];
      }
    }
    cout<<a;
    a.pop_back();
    cout<<endl<<a;
  return 0;
}
