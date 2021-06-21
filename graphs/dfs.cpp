//dfs
#include <bits/stdc++.h>
using namespace std;
int flag =0;
void isCycle(vector<vector<int>> &graph, int cur, int parent, vector<int> &visited){
    visited[cur] = true;
    for (auto i : graph[cur])
    {
        if (!visited[i])
            isCycle(graph, i,cur, visited );
        if(visited[i]&&(parent!=cur||i==cur))
            flag=1;

        }

}
int main()
{
    vector<vector<int>> g;
    stack<int> st;
    vector<int> visited(g.size(), 0);
    int s; //start node
    visited[s] = 1;
    st.push(s);
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        for (auto nbr : g[curr])
        {
            cout << nbr << endl;
            if (!visited[nbr])
            {
                st.push(nbr);
                visited[nbr] = 1;
            }
        }
    }
    return 0;
}
