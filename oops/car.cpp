#include <bits/stdc++.h>
using namespace std;

class Car{
  public:
  void topSpeed(long input){
    cout<<" Top speed is long "<<input<<endl;
  }

  void topSpeed(int input)
  {
    cout << " Top speed is integer " << input << endl;
  }
};

void topSpeed(double input)
{
  cout << " Top speed is double " << input << endl;
}
int main(){
  Car car;
  long max =LONG_MAX/2000000;
  car.topSpeed(max);
  return 0;
}
