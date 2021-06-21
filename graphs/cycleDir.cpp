#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
int visit[100];
int flag = 0;
void cycleTest(int current){
  visit[current] = 1;//processing state
  for(auto i: graph[current]){
    if(visit[i]==1)
      flag=1;
    else
      if(visit[i]==0)
        cycleTest(i);
  }
  visit[current] = 2;
}
int main(){
  
  graph = {{},{2,3},{7,8},{4,5},{6},{6},{},{9},{},{8}};
  // unvisited = -0, completely visited =2, currently processing =1
  int n =graph.size();
  memset(visit,0,sizeof(visit));
  for(int i=0;i<n;i++){
    cycleTest(i);
  }
  if (flag==1)
    cout<<"Cyclic Directed Graph\n";
  else  
    cout<<"Acyclic Directed Graph\n";
  return 0;
}
