class RandomizedCollection
{
public:
  /** Initialize your data structure here. */
  multimap<int, int> m;
  int i = 0;
  RandomizedCollection()
  {
  }

  /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
  bool insert(int val)
  {
    if (m.find(val) != m.end())
    {
      m.insert({val, ++i});
      return false;
    }
    m.insert({val, 1});
    return true;
  }

  /** Removes a value from the collection. Returns true if the collection contained the specified element. */
  bool remove(int val)
  {
    auto it = m.find(val);
    if (it == m.end())
      return false;
    m.erase(it);
    return true;
  }

  /** Get a random element from the collection. */
  int getRandom()
  {
    auto it = m.begin();
    std::advance(it, rand() % m.size());
    int random = it->first;
    return random;
  }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */