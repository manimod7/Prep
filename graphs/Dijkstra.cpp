#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<vector<pair<int, int>>> graph{{{1, 1}, {2, 4}}, 
                                      {{0, 1}, {2, 4},{3,2}, {4, 7}}, 
                                      {{0, 4}, {1, 4}, {3, 3}, {4, 5}},
                                      {{1, 2},{2,3},{4,4},{5,6}}, 
                                      {{1,7},{2,5},{3,4},{5,7}}, 
                                      {{3,6},{4,7}}};
  
  //vector<vector<pair<<node, dist>>>
  vector<int> dist (6,INT_MAX);
  // int start =0;
  dist[0] = 0;
  queue<pair<int, int>> q;
  pair<int,int> start {0,0};
  q.push(start);
  while(!q.empty()){
    pair<int, int> curr =q.front();
    q.pop();
    int currNode =curr.first;
    int currDist = curr.second;
    for(auto nbrPair: graph[currNode]){
      if(currDist +nbrPair.second <dist[nbrPair.first]){
        dist[nbrPair.first] = currDist + nbrPair.second;
        q.push({nbrPair.first, dist[nbrPair.first]});
      }
    }
  }
  for(int i=0;i<6;i++){
    cout<< dist[i]<<" ";
  }
  return 0;
}
