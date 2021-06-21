#include<bits/stdc++.h>
using namespace std;

int flag = 0;
void isCycleTest(map<int, vector<int>> &graph , int cur, int parent, vector<bool> &visited)
{
  visited[cur] = true;
  //cout<<cur<<endl;
  for (auto i : graph[cur])
  {
    if (!visited[i]){
   // cout<<"Calling recursive function for curr= "<<cur<<" and i = "<<i<<endl;
      isCycleTest(graph, i, cur, visited);
      }
    
    else{ 
      if ((visited[i])&&(parent != i || i == cur)){
      flag = 1;
     // cout<<"\nBecause of "<<i<<" and "<<cur<<endl;
    }
    }
    
  }
}
  int main()
  { map<int, vector<int>> graph;
  graph[1]={2,5};
  graph[2] = {3,1};
  graph[3] = {2,4};
  graph[4] = {3,7};
  graph[5] = {1,6,12};
  graph[6] = {5,11};
  graph[7] = {4,9,8};
  graph[8] = {7,10};
  graph[9] = {7};
  graph[10] = {8};
  graph[11] = {6};
  // graph[12] = {9,10};
  

  vector<bool> visited(graph.size(), false);
  int n =graph.size();
  for(int i=0;i<n;i++){
    if(!visited[i])
      isCycleTest(graph,i,-1, visited);
  }
  if(flag==1)
    cout<<"Cyclic\n";
  else
    cout<<"Not Cyclic\n";
  return 0;
  }