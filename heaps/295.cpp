class MedianFinder
{
private:
  priority_queue<int> maxHeap;
  priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

public:
  // Adds a number into the data structure.
  void addNum(int num)
  {
    if (maxHeap.empty() || (maxHeap.top() > num))
      maxHeap.push(num);
    else
      minHeap.push(num);

    if (maxHeap.size() > (minHeap.size() + 1))
    {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    }
    else if (maxHeap.size() + 1 < minHeap.size())
    {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }

  double findMedian()
  {
    if (maxHeap.size() == minHeap.size())
      return maxHeap.empty() ? 0 : ((maxHeap.top() + minHeap.top()) / 2.0);
    else
      return (maxHeap.size() > minHeap.size()) ? maxHeap.top() : minHeap.top();
  }
};