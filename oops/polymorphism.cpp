#include "iostream"
using namespace std;

class A
{
  int a, b, c;

public:
  void add(int x, int y)
  {
    a = x;
    b = y;
    cout << "addition of a+b is:" << (a + b) << endl;
  }

  void add(int x, int y, int z)
  {
    a = x;
    b = y;
    c = z;
    cout << "addition of a+b+c is:" << (a + b + c) << endl;
  }

  void print()
  {
    cout << "Class A's method is running" << endl;
  }
};

class B : public A
{
public:
  void print()
  {
    cout << "Class B's method is running" << endl;
  }
};

int main()
{
  A a1;

  // method overloading (Compile-time polymorphism)
  a1.add(6, 5);

  // method overloading (Compile-time polymorphism)
  a1.add(1, 2, 3);

  B b1;

  // Method overriding (Run-time polymorphism)
  b1.print();
}
