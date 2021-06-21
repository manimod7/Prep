#include <bits/stdc++.h>
using namespace std;

int main(){

  vector<string> d{"hot", "dot", "dog", "lot", "log", "cog"};
  unordered_set<string> dict(d.begin(),d.end());
  unordered_map<string, set<string>> graph;
  unordered_set<string> visited;
  string beginWord ="hit";
  int n = beginWord.size();
  string endWord = "cog";
  string currWord, tempWord;
  int currDist = 1;
  // string tempWord =currWord;
  queue<string> q;
  q.push(beginWord);
  while(!q.empty()){
    visited.insert(currWord);
    currWord =q.front();
    tempWord= currWord;
    q.pop();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < 26; j++)
      {
        tempWord[i] = (char)'a' + j;
        if ((dict.find(tempWord) != dict.end()||tempWord==beginWord)&&tempWord!=currWord)
        { if(visited.find(tempWord)==visited.end())
            q.push(tempWord);
          graph[currWord].insert(tempWord);
        }
      }
      tempWord[i] = currWord[i];
    }
  }
  for(auto i : graph){
    cout<<" "<<i.first<<" - ";
    for (string j: graph[i.first]){
      cout<< j<<" ";
    }
    cout<<endl;
  }

  return 0;
}
