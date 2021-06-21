#include <bits/stdc++.h>
using namespace std;

class AllOne
{
public:
  /** Initialize your data structure here. */
  map<string, int> key_value;
  map<int, set<string>> value_key;
  AllOne()
  {
  }

  /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
  void inc(string key)
  {
    if (key_value[key] == 0)
    {
      key_value[key]++;
      value_key[1].insert(key);
    }
    else
    {
      int freq = key_value[key];
      value_key[freq].erase(key);
      if(value_key[freq].empty())
        value_key.erase(freq);
      value_key[freq + 1].insert(key);
      key_value[key]++;
    }
  }

  /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
  void dec(string key)
  {
    if (key_value[key] == 0)
      return;
    if (key_value[key] == 1)
    {
      key_value[key]--;
      value_key[1].erase(key);
      if (value_key[1].empty())
        value_key.erase(1);
    }
    else
    {
      int freq = key_value[key];
      value_key[freq].erase(key);
      if (value_key[freq].empty())
        value_key.erase(freq);
      value_key[freq - 1].insert(key);
      key_value[key]--;
    }
  }

  /** Returns one of the keys with maximal value. */
  string getMaxKey()
  {
    if (value_key.size() == 0)
      return "abcd";
    auto maxKey = value_key.rbegin();
    auto itr = maxKey->second;
    auto ele = itr.begin();
    if (ele == itr.end())
      return "";
    return *ele;
  }

  /** Returns one of the keys with Minimal value. */
  string getMinKey()
  {
    // if(value_key.size()==0)
    //     return "abcd";
    auto minKey = value_key.begin();
    auto itr = minKey->second;
    auto ele = itr.begin();
    if (ele == itr.end())
      return "abcd";
    return *ele;
  }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main(){
  AllOne a;
  a.inc("hello");
  a.inc("hello");
  cout<<a.getMaxKey();
  cout<<a.getMinKey();
  return 0;
}
