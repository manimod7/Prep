#include <bits/stdc++.h>
using namespace std;
#define V 6 //No of vertices
int graph[V][V] =  {{0, 1, 4, INT_MAX, INT_MAX, INT_MAX},
                {INT_MAX, 0, 4, 2, 7, INT_MAX},
                {INT_MAX, INT_MAX, 0, 3, 4, INT_MAX},
                {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
                {INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
                {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0}};
void floyd_warshall()
{
  for (int k = 0; k < V; ++k) //Try all intermediate nodes
  {
    for (int i = 0; i < V; ++i) //Try for all possible starting position
    {
      for (int j = 0; j < V; ++j) //Try for all possible ending position
      {
        if (graph[i][k] == INT_MAX || graph[k][j] == INT_MAX) //SKIP if K is unreachable from i or j is unreachable from k
          continue;

        else if (graph[i][k] + graph[k][j] < graph[i][j]) //Check if new distance is shorter via vertex K

          graph[i][j] = graph[i][k] + graph[k][j];
      }
    }
  }

  //Check for negative edge weight cycle
  for (int i = 0; i < V; ++i)

    if (graph[i][i] < 0)
    {
      cout << "Negative edge weight cycle is present\n";
      return;
    }

  //Print Shortest Path Graph
  //(Values printed as INT_MAX defines there is no path)

  for (int i = 1; i < V; ++i)
  {
    for (int j = 0; j < V; ++j)

      cout << i << " to " << j << " distance is " << graph[i][j] << "\n";

    cout << "=================================\n";
  }
}

int main()
{


  //These are the direct edges.
  //graph[i][j] is direct edge from i to j value
  floyd_warshall();
  return 0;
}
//TIME COMPLEXITY: O(V^3)