#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int main(){

  int arr[10] = {2,11,4,1,7,9,-5,-10,72,0};

  int i, j;
  //Traversing over the array.
  for (i = 0; i < 9; i++)
  {
    for (j = 0; j < 9 - i - 1; j++)
      if(arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
  }

  return 0;
}
