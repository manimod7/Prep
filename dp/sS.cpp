// *Check if there is a subset whose sum is equal to a given value

#include <bits/stdc++.h>
using namespace std;
int main(){
  int sum, size;
  cout << "Enter size of array\n";
  cin >> size;
  vector<int> arr(size, 0);
  cout << "Enter elements of the array\n";
  for (int i = 0; i < size; i++)
  {
    int temp;
    cin >> temp;
    arr[i] = temp;
  }
  cout << "Enter sum of subset array\n";
  cin >> sum;
  bool t[size + 1][sum + 1];
  for (int i = 0; i < size + 1; i++)
    t[i][0] = true;
  for (int j = 1; j < sum + 1; j++)
    t[0][j] = false;
  for (int i = 1; i < size + 1; i++)
  {
    for (int j = 1; j < sum + 1; j++)
    {
      if (arr[i - 1] <= j)
        t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
      else
        t[i][j] = t[i - 1][j];
      cout<<t[i][j]<<" ";
    }
    cout<<endl;
  }
  cout <<endl<<endl<< t[size][sum];

  return 0;
}
