#include<bits/stdc++.h>
using namespace std;


class Calculator{
  public:
  Calculator(string x){
    this->s = x;
  }
  string s;
  stack<string> d;

  void division(){
    string temp;
    int n = s.size();
    for(int i=0;i<n;i++){
      if(s[i]!='/'){
        temp+= s[i]; 
      }
      
      else {
        d.push(to_string(s[i]));
        string s1 = d.top();
        int top = stoi(s1);
        d.pop();
        if(s[i+1]=='0')
          {
            cout<<"Can't divide by zero\n ";
            return;
          }
        if(top%(int)s[i+1]!=0){
          float q = top/(int)(s[i+1]);
          int Intval = (int)q;
          int x1 = (int)(q*10)%10;
          int x2 = (int)(q*100)%10;
          d.push(to_string(Intval));
          d.push(".");
          d.push(to_string(x1));
          d.push(to_string(x2));

        }
        else
        {
          int tempAns = top /(s[i + 1]-'0');
          i++;
          d.push(to_string(tempAns));
        }
      }
    }
    while(!d.empty()){
      cout<<d.top();
      d.pop();
    }
  }
};

  // void mult(){

  //   for(int i=0;i<d.size();i++){

  //   }
int main()
{
    string s ="100/10/5";
    Calculator *c1 = new Calculator(s);
    c1->division();
    

  return 0;
}
// 1*2+5-12/6 +4*2