#include <bits/stdc++.h>
using namespace std;
class comp{
  public:
    bool operator()(const int &a,const  int &b)
    {
      return a<=b;
    }
};


int main(){
  priority_queue<int, vector<int>, comp > pq;
  for(int i=0;i<=10;i++){
    pq.push(i);
  }
  
  while(!pq.empty()){
    cout<<pq.top()<<endl;
    pq.pop();
  }
  return 0;
}
