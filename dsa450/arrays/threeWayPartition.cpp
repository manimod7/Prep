class Solution
{
public:
  //Function to partition the array around the range such
  //that array is divided into three parts.
  void threeWayPartition(vector<int> &arr, int lowVal, int highVal)
  {
    // code here
    int n = arr.size();
    int start = 0, end = n - 1;

    // Traverse elements from left
    for (int i = 0; i <= end;)
    {
      // If current element is smaller than
      // range, put it on next available smaller
      // position.
      if (arr[i] < lowVal)
        swap(arr[i++], arr[start++]);

      else if (arr[i] > highVal)
        swap(arr[i], arr[end--]);

      else
        i++;
    }
  }
};