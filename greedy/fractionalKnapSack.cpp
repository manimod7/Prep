class Solution
{
public:
  static bool cmp(Item a, Item b)
  {
    return ((double)a.value / (double)a.weight) > ((double)b.value / (double)b.weight);
  }
  //Function to get the maximum total value in the knapsack.
  double fractionalKnapsack(int W, Item arr[], int n)
  {
    // Your code here
    sort(arr, arr + n, cmp);
    int index;
    int currWt = 0;
    double ans = 0.0;
    for (int i = 0; i < n; i++)
    {
      if (W >= currWt + arr[i].weight)
      {
        currWt += arr[i].weight;
        ans += arr[i].value;
      }
      else
      {
        int remain = W - currWt;
        ans += arr[i].value * ((double)remain / (double)arr[i].weight);
        break;
      }
    }

    return ans;
  }
};