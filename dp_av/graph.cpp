//bfs
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> g;
    queue<int> q;
    vector<int> visited(g.size(),0);
    int s;//start node
    visited[s]=1;
    q.push(s);
    while(!q.empty()){
        int curr =q.front();
        q.pop();
        for(auto nbr:g[curr]){
            cout<<nbr<<endl;
            if(!visited[nbr])
            {
                q.push(nbr);
                visited[nbr]=1;
            }
        }
    }
    return 0;
}