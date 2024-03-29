class Solution
{
public:
  void wiggleSort(vector<int> &nums)
  {
    vector<int> sorted(nums);
    z
        sort(sorted.begin(), sorted.end());
    for (int i = nums.size() - 1, j = 0, k = i / 2 + 1; i >= 0; i--)
      nums[i] = sorted[i & 1 ? k++ : j++];
  }
};
// Sort and then write the smaller half of the numbers on the even indexes and the larger half of the numbers on the odd indexes, both from the back. Example:

// 0 1 2 3 4 5 6 7 8 9
// Small half:    4 . 3 . 2 . 1 . 0 .
// Large half:    . 9 . 8 . 7 . 6 . 5
// ----------------------------------
// Together:      4 9 3 8 2 7 1 6 0 5
//[ 1, 5, 1, 1, 6, 4 ]
