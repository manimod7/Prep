class Solution
{
public:
  int trap(vector<int> &height)
  {

    //left[i] = max height of a building on the left of i
    //right[i] =max height of a building on the right of i

    int n = height.size(), res = 0;

    vector<int> left(n, 0);
    vector<int> right(n, 0);

    for (int i = 1; i < n; i++)
    {
      left[i] = max(left[i - 1], height[i - 1]);
      //cout<<left[i]<<" ";
    }
    //cout<<endl;

    for (int i = n - 2; i >= 0; i--)
    {
      right[i] = max(right[i + 1], height[i + 1]);
      //cout<<right[i]<<" ";
    }
    //cout<<endl;

    for (int i = 1; i < n - 1; i++)
    {
      int temp = min(left[i], right[i]) - height[i];
      if (temp > 0)
        res += temp;
    }
    return res;
  }
};