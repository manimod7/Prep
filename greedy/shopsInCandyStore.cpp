vector<int> candyStore(int arr[], int N, int k)
{
    // Write Your Code here
    sort(arr, arr + N);
    int n=N;
    int minRes = 0;
    int maxRes =0;
    for (int i = 0; i < n; i++) {
        // Buy current candy
        minRes += arr[i];

        // And take k candies for free
        // from the last
        n = n - k;
    }
    int  index = 0;
    n=N;
    for (int i = n - 1; i >= index; i--)
    {
        // Buy candy with maximum amount
        maxRes += arr[i];

        // And get k candies for free from
        // the starting
        index += k;
    }
    return {minRes, maxRes};
}