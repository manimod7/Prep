//Max_Heap Solution
class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {

    //Pair<int,int> contains (nums[i],index)

    priority_queue<pair<int, int>> heap;
    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i)
    {
      while (!heap.empty() and heap.top().second <= (i - k))
        heap.pop();
      heap.push(make_pair(nums[i], i));
      if (i >= k - 1)
        ans.push_back(heap.top().first);
    }
    return ans;
  }
};