#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int main(){

int len=15;
int arr[15] ={1,2,3,1,6,9,14,1,5,7,1,-5,4,4,11};
int i, j;
for (i = 0; i < len - 1; i++)
{
  for (j = 0; j < len - i - 1; j++)
  {
    int temp = 0;
    if (arr[j] < arr[j + 1])
    {
      temp = arr[j];
      arr[j] = arr[j + 1];
      arr[j + 1] = temp;
    }
  }
}
  cout << "Hello";
  return 0;
};


     
// Last i elements are already in place

