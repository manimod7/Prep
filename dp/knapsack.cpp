#include <bits/stdc++.h>
using namespace std;
int main(){
  //Bounded Knapsack(0,1 Knapsack)

  vector<vector<int>> T;
  vector<int> weight, value;
  int i,j;
  if(weight[i-1]<=j)
    T[i][j] = max( (value[i-1] + T[i-1][j - weight[i-1]]), T[i-1][j]) ;
  else 
    T[i][j] = T[i - 1][j];

  //Unbounded Knapsack

  if (weight[i - 1] <= j)
    T[i][j] = max( (value[i-1] + T[i][j - weight[i-1]]), T[i-1][j]) ;
  else
    T[i][j] = T[i - 1][j];
  return 0;
}
