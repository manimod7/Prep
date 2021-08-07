// A program with virtual destructor
#include <iostream>

using namespace std;

class base
{
public:
  base()
  {
    cout << "Constructing base \n";
  }
  virtual ~base()
  {
    cout << "Destructing base \n";
  }
};

class derived : public base
{
public:
  derived()
  {
    cout << "Constructing derived \n";
  }
  ~derived()
  {
    cout << "Destructing derived \n";
  }
};

int main(void)
{
  derived *d = new derived();
  base *b = d;
  delete b;
  getchar();
  return 0;
}
//1 Base COnstructor
//2 Derive const
//3. Delete derive
//4. Delete base
//1 2 3 4
//2 1 3 4
//2 1 4 3
//1 2 4 3
