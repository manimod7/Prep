#include<bits/stdc++.h>
using namespace std;

int findNthEvenDigitNumber(int n)
{
  
  if (n == 1)
    return 0;

  
  vector<int> v;

  
  n = n - 1;


  while (n > 0)
  {

    v.push_back(n % 5);
    n = n / 5;
  }

 
  int result = 0;
  for (int i = v.size() - 1; i >= 0; i--)
  {
    result = result * 10;
    result = result + v[i];
  }


  return 2 * result;
}

int main()
{
  int k;
  cin>>k;
  vector<int>arr(k,0);

  for(int i=0;i<k;i++){
    cin>>arr[i];
    
  }
  for(int i=0;i<k;i++)
    cout << findNthEvenDigitNumber(arr[i])<<endl;
}

