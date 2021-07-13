class FreqStack
{
public:
  unordered_map<int, stack<int>> nums; // <frequency, stack of all numbers with that frequqncy>
  unordered_map<int, int> frq;         // <number, frequency>
  int maxFreq = 0;
  FreqStack()
  {
  }
  void push(int x)
  {
    nums[++frq[x]].push(x);
    maxFreq = max(maxFreq, frq[x]);
  }

  int pop()
  {
    int popped = nums[maxFreq].top();
    nums[maxFreq].pop();
    frq[popped]--;
    if (nums[maxFreq].empty())
      maxFreq--;
    return popped;
  }
};
//1 1 2 4 3 2 2 4