#include<bits/stdc++.h>
using namespace std;

class Vehicle {

private:
  string t;
  int maxSpeed;
  int mileage;

public:
  Vehicle(){
    cout<<"Vehicle made\n";
  }
  virtual ~Vehicle(){
    cout<<"Vehicle destroyed\n";
  }
  
  
  virtual void displayType(){

  };
  virtual void engine(int x, int y){
    cout<<"Vehicle with power "<<x<<" and "<<y<<endl;
  };
  virtual void engine(int x){};
  void setMaxSpeed(int s){
    this->maxSpeed =s;
  }
  
  int getMaxSpeed(){
    return this->maxSpeed;
  }

  void setMileage(int m){
    this->mileage = m;
  }
  int getMileage(){
    return this->mileage;
  }
};
class Aeroplane : public Vehicle{
  public:
    Aeroplane()
    {
      cout << "Aeroplane made\n";
    }
    ~Aeroplane()
    {
      cout << "Aeroplane destroyed\n";
    }
  void displayType(){
    cout<<"This is a Aeroplane\n";
  }
  void engine (int a, int b){
    cout<<"Double Engine with power "<<a<<" and "<<b<<endl;
  }
  void engine(int a)
  {
    cout << "Single Engine with power " << a << endl;
  }
};
int main()
{
  // Vehicle *v1 = new Aeroplane();
  // v1->displayType();
  // int a =4, b=5, c=10;
  // v1->engine(a,b);
  // v1->engine(c);
  // delete v1;

  // v1.setMaxSpeed(25);
  // int s = v1.getMaxSpeed();
  // cout<<s<<endl;
  Vehicle v1;
  v1.engine(4,5);
  //delete v1;
  return 0;
}