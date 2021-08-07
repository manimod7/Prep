#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;
class A {
  public:
  virtual void hello(){

  };
};
class B :public A{
  public:
  void hello(){
    cout<<"Hello\n";
  };
};

int main(){

  B *b =new B();
  b->hello();
  return 0;
}
